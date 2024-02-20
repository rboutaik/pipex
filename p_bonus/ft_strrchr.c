/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:47:05 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/05 19:54:19 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strrchr(const char *s, int c)
{
	char	x;
	int		loc;
	int		i;

	x = (char )c;
	loc = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == x)
			loc = i;
		i++;
	}
	if (s[i] == x)
		return ((char *)s + i);
	else if (loc != -1)
		return ((char *)s + loc);
	return (NULL);
}
