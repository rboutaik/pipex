/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:16:53 by rboutaik          #+#    #+#             */
/*   Updated: 2024/02/16 20:19:54 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_here_doc(char *limiter)
{
	int		fd;
	char	*str;

	fd = open("/tmp/.hg", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		(perror("open file fail : "), exit(EXIT_FAILURE));
	ft_putstr_fd("here_doc>", 1);
	str = get_next_line(0);
	limiter = ft_strjoine(limiter, "\n");
	while (ft_strncmp(limiter, str, ft_strlen(limiter)))
	{
		ft_putstr_fd(str, fd);
		free(str);
		ft_putstr_fd("here_doc>", 1);
		str = get_next_line(0);
		if (!str)
			break ;
	}
	close(fd);
	(free(str), free(limiter));
	return (1);
}

size_t	ft_strlen(const char *c)
{
	size_t	n;

	n = 0;
	while (c[n])
		n++;
	return (n);
}

char	*ft_strjoine(char const *s1, char const *s2)
{
	int		size;
	int		i;
	char	*str;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	j = ft_strlen(s1);
	while (s2[++i])
		str[i + j] = s2[i];
	str[i + j] = '\0';
	return (str);
}
