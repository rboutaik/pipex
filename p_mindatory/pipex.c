/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:54:43 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/16 10:00:00 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *c)
{
	size_t	n;

	n = 0;
	while (c[n])
		n++;
	return (n);
}

void	ft_callsecondchild(char **paths, int fd[], char **argv, char **env)
{
	int		ouf;
	char	*path;
	char	**cmdopt;

	close(fd[1]);
	ouf = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (ouf == -1)
		(ft_free(paths), perror("output file failure: "), exit(EXIT_FAILURE));
	if (dup2(ouf, STDOUT_FILENO) == -1 || dup2(fd[0], STDIN_FILENO) == -1)
		(ft_free(paths), perror("Dup failure : "), exit(EXIT_FAILURE));
	(close(fd[0]), close(ouf));
	if (ft_strrchr(argv[3], '/')
		&& access(ft_split(argv[3], ' ')[0], F_OK | R_OK) != -1)
		cmdopt = ft_split(ft_strrchr(argv[3], '/') + 1, ' ');
	else
		cmdopt = ft_split(argv[3], ' ');
	path = ft_get_path(paths, cmdopt);
	if (execve(path, cmdopt, env) == -1)
	{
		(ft_free(paths), ft_free(cmdopt), free(path));
		(perror("Execve failed :"), exit(EXIT_FAILURE));
	}
}

void	ft_callchild(char **paths, int fd[], char **argv, char **env)
{
	int		inf;
	char	*path;
	char	**cmdopt;

	close(fd[0]);
	inf = open(argv[1], O_RDONLY);
	if (inf == -1)
		(ft_free(paths), perror("inf error"), exit(EXIT_FAILURE));
	if (dup2(inf, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		(ft_free(paths), perror("Dup failure : "), exit(EXIT_FAILURE));
	(close(fd[1]), close(inf));
	if (ft_strrchr(argv[2], '/')
		&& access(ft_split(argv[2], ' ')[0], F_OK | R_OK) != -1)
		cmdopt = ft_split(ft_strrchr(argv[2], '/') + 1, ' ');
	else
		cmdopt = ft_split(argv[2], ' ');
	path = ft_get_path(paths, cmdopt);
	if (execve(path, cmdopt, env) == -1)
	{
		(ft_free(paths), ft_free(cmdopt), free(path));
		(perror("Execve failed :"), exit(EXIT_FAILURE));
	}
}

int	main(int argc, char *argv[], char **env)
{
	int		fd[2];
	pid_t	pid[2];
	char	**paths;
	char	*p;

	if (argc != 5)
		(ft_putstr_fd("EX: infile cmd1 cmd2 outfile", 2), exit(EXIT_FAILURE));
	if (pipe(fd) == -1)
		(perror("Pipe error :"), exit(EXIT_FAILURE));
	p = ft_getpaths(env);
	paths = ft_split(p, ':');
	free(p);
	if (paths == NULL)
		(ft_putstr_fd("Paths not found", 2), exit(EXIT_FAILURE));
	pid[0] = fork();
	if (pid[0] == -1)
		(ft_free(paths), perror("Fork error :"), exit(EXIT_FAILURE));
	if (pid[0] == 0)
		ft_callchild(paths, fd, argv, env);
	pid[1] = fork();
	if (pid[1] == -1)
		(ft_free(paths), perror("Pipe error :"), exit(EXIT_FAILURE));
	if (pid[1] == 0)
		ft_callsecondchild(paths, fd, argv, env);
	(ft_free(paths), close(fd[0]), close(fd[1]), wait(NULL), wait(NULL));
}
