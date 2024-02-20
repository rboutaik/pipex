/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:56:59 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/02 18:01:16 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_sstrcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i + 1] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char )s2[i]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ns;

	ns = ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (ft_sstrcmp(needle, &haystack[i]) == 0 && ns + i <= len)
				return (((char *)&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
