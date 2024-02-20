/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:11:03 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/10 04:45:58 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	size;

	size = 0;
	if (s == NULL || fd < 0 || fd > 1023)
		return ;
	while (s[size])
		size++;
	write(fd, s, size);
}

void	ft_free(char **paths)
{
	int	i;

	i = -1;
	if (paths == NULL)
		return ;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

char	*ft_getpaths(char **env)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH", 5) != NULL)
			return (ft_substr(*env, 5, ft_strlen(*env)));
		env++;
	}
	return (NULL);
}

char	*ft_get_path(char **paths, char **cmd)
{
	char	*path;

	while (*paths)
	{
		path = ft_strjoine(*paths, ft_strjoine("/", cmd[0]));
		if (!access(path, F_OK | X_OK))
			return (path);
		paths++;
		free(path);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		size;
	int		i;

	size = 0;
	while (s1[size])
		size++;
	copy = (char *)malloc((size + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
