/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:04:52 by rboutaik          #+#    #+#             */
/*   Updated: 2024/01/11 03:39:54 by rboutaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# define PIPEX_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

size_t	ft_strlen(const char *c);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getstr(char *s);
char	*ft_getsecond(char *s);
char	*ft_allocat2(int size, char **s1, char **s2);
char	*ft_allocat(char **str, int s);
int		f(char **str, char **buffer, int size);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *c);
char	**ft_split(char const *s, char c);
char	*ft_strjoine(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_free(char **paths);
char	*ft_getpaths(char **env);
char	*ft_get_path(char **paths, char **cmd);
void	ft_callsecondchild(char **paths, int fd[], char **argv, int c[]);
void	ft_callchild(char **paths, int fd[], char **argv, int c[]);
char	*ft_strdup(const char *s1);
char	*ft_strrchr(const char *s, int c);
void	ft_callrest(char **paths, int fd[], char **argv, int i);
void	ft_execute_cmds(int argc, char **argv, char **paths, int k);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_here_doc(char *limiter);

#endif