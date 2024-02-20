/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:28:07 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/11 03:35:42 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	x;

	x = (char)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == x)
			return ((char *)s);
		s++;
	}
	if (x == *s)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*str;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 != NULL && s2 == NULL)
		return (s1);
	else if (s1 == NULL && s2 != NULL)
		return (s2);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = ft_allocat2(size, &s1, &s2);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	j = ft_strlen(s1);
	free(s1);
	while (s2[++i])
		str[i + j] = s2[i];
	str[i + j] = '\0';
	return (free(s2), str);
}

char	*ft_getstr(char *s)
{
	char	*str;
	int		size;

	size = 0;
	while (s[size] && s[size] != '\n')
		size++;
	if (s[size] == '\n')
		size++;
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	size = 0;
	while (s[size] && s[size] != '\n')
	{
		str[size] = s[size];
		size++;
	}
	if (s[size] == '\n')
	{
		str[size] = s[size];
		size++;
	}
	str[size] = '\0';
	return (str);
}

char	*ft_getsecond(char *s)
{
	int		i;
	int		j;
	int		size;
	char	*strs;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0' || (s[i] == '\n' && !s[i + 1]))
		return (free(s), NULL);
	size = ft_strlen(s) - i;
	strs = ft_allocat(&s, size);
	if (!strs)
		return (NULL);
	j = 0;
	--size;
	i = ft_strlen(s);
	while (s[i - size + j])
	{
		strs[j] = s[i - size + j];
		j++;
	}
	return (free(s), strs[j] = '\0', strs);
}
