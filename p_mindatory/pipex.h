/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:04:52 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/16 09:22:15 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_free(char **paths);
char	*ft_getpaths(char **env);
char	*ft_get_path(char **paths, char **cmd);
void	ft_callsecondchild(char **paths, int fd[], char **argv, char **env);
void	ft_callchild(char **paths, int fd[], char **argv, char **env);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);

#endif