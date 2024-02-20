/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:54:43 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/16 09:37:47 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_callsecondchild(char **paths, int fd[], char **argv, int c[])
{
	int		ouf;
	char	*path;
	char	**cmdopt;

	close(fd[1]);
	if (c[2] == 1)
		ouf = open(argv[c[1] - 1], O_RDWR | O_APPEND | O_CREAT, 0777);
	else
		ouf = open(argv[c[1] - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (ouf == -1)
		(ft_free(paths), perror("output file failure: "), exit(EXIT_FAILURE));
	if (dup2(ouf, STDOUT_FILENO) == -1)
		(ft_free(paths), perror("Dup failure : "), exit(EXIT_FAILURE));
	close(ouf);
	if (ft_strrchr(argv[c[0]], '/')
		&& access(ft_split(argv[c[0]], ' ')[0], F_OK | R_OK) != -1)
		cmdopt = ft_split(ft_strrchr(argv[c[0]], '/') + 1, ' ');
	else
		cmdopt = ft_split(argv[c[0]], ' ');
	path = ft_get_path(paths, cmdopt);
	if (execve(path, cmdopt, NULL) == -1)
	{
		(ft_free(paths), ft_free(cmdopt), free(path));
		(perror("Execve failed :"), exit(EXIT_FAILURE));
	}
}

void	ft_callchild(char **paths, int fd[], char **argv, int c[])
{
	int		inf;
	char	*path;
	char	**cmdopt;

	close(fd[0]);
	if (c[2] == 1)
		inf = open("/tmp/.hg", O_RDONLY);
	else
		inf = open(argv[1], O_RDONLY);
	if (inf == -1)
		(ft_free(paths), perror("inf error"), exit(EXIT_FAILURE));
	if (dup2(inf, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		(ft_free(paths), perror("Dup failure : "), unlink("/tmp/.hg"), exit(1));
	close(inf);
	if (ft_strrchr(argv[2], '/')
		&& access(ft_split(argv[c[0]], ' ')[0], F_OK | R_OK) != -1)
		cmdopt = ft_split(ft_strrchr(argv[c[0]], '/') + 1, ' ');
	else
		cmdopt = ft_split(argv[c[0]], ' ');
	path = ft_get_path(paths, cmdopt);
	if (execve(path, cmdopt, NULL) == -1)
	{
		(ft_free(paths), ft_free(cmdopt), free(path)), unlink("/tmp/.hg");
		(perror("Execve failed :"), exit(EXIT_FAILURE));
	}
}

void	ft_callrest(char **paths, int fd[], char **argv, int i)
{
	char	*path;
	char	**cmdopt;

	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		(ft_free(paths), perror("Dup failure : "), exit(EXIT_FAILURE));
	close(fd[1]);
	if (ft_strrchr(argv[i], '/')
		&& access(ft_split(argv[i], ' ')[0], F_OK | R_OK) != -1)
		cmdopt = ft_split(ft_strrchr(argv[i], '/') + 1, ' ');
	else
		cmdopt = ft_split(argv[i], ' ');
	path = ft_get_path(paths, cmdopt);
	if (execve(path, cmdopt, NULL) == -1)
	{
		(ft_free(paths), ft_free(cmdopt), free(path));
		(perror("Execve failed :"), exit(EXIT_FAILURE));
	}
}

void	ft_execute_cmds(int argc, char **argv, char **paths, int k)
{
	pid_t	pid;
	int		c[3];
	int		fd[2];

	c[0] = 1 + k;
	c[1] = argc;
	c[2] = k;
	while (++c[0] < argc - 1)
	{
		if (pipe(fd) == -1)
			(perror("Pipe fails"), ft_free(paths), exit(EXIT_FAILURE));
		pid = fork();
		if (pid == -1)
			(perror("Fork fails"), ft_free(paths), exit(EXIT_FAILURE));
		if (pid == 0)
		{
			if (c[0] == 2 + k)
				ft_callchild(paths, fd, argv, c);
			else if (c[0] == argc - 2)
				ft_callsecondchild(paths, fd, argv, c);
			ft_callrest(paths, fd, argv, c[0]);
		}
		dup2(fd[0], STDIN_FILENO);
		(close(fd[1]), close(fd[0]));
	}
}

int	main(int argc, char *argv[], char **env)
{
	char	**paths;
	char	*p;
	int		i;
	int		k;

	k = 0;
	if (argc < 5)
		(ft_putstr_fd("EX: ifile cmd1 cmd2 ... oufile", 2), exit(EXIT_FAILURE));
	if (!ft_strncmp(argv[1], "here_doc", 9))
		k = ft_here_doc(argv[2]);
	p = ft_getpaths(env);
	paths = ft_split(p, ':');
	free(p);
	if (paths == NULL)
		(ft_putstr_fd("Paths not found", 2), exit(EXIT_FAILURE));
	ft_execute_cmds(argc, argv, paths, k);
	(ft_free(paths), i = 0);
	while (i < argc - 3)
		(wait(NULL), i++);
	unlink("/tmp/.hg");
}
