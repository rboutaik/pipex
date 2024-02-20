# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboutaik <rboutaik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 14:15:43 by rboutaik          #+#    #+#              #
#    Updated: 2024/01/16 10:13:28 by rboutaik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = pipex

BNAME = pipex_bonus

MPATH = ./p_mindatory/

BPATH = ./p_bonus/

CFILES = $(MPATH)pipex.c $(MPATH)pipex_utils.c $(MPATH)ft_split.c $(MPATH)ft_strjoin.c $(MPATH)ft_strnstr.c $(MPATH)ft_substr.c $(MPATH)ft_strrchr.c

BCFILES = $(BPATH)pipex_bonus.c $(BPATH)pipex_utils.c $(BPATH)ft_split.c $(BPATH)ft_strjoin.c $(BPATH)ft_strnstr.c $(BPATH)ft_substr.c $(BPATH)ft_strrchr.c $(BPATH)ft_strncmp.c $(BPATH)get_next_line.c $(BPATH)get_next_line_utils.c

OFILES = $(CFILES:.c=.o)

BOFILES = $(BCFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES) $(MPATH)pipex.h
	$(CC) $(FLAGS) -o $@ $(OFILES)

$(MPATH)%.o : $(MPATH)%.c $(MPATH)pipex.h
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(BNAME)

$(BNAME) : $(BOFILES) $(BPATH)pipex_bonus.h
	$(CC) $(FLAGS) -o $@ $(BOFILES)

$(BPATH)%.o : $(BPATH)%.c $(BPATH)pipex_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OFILES) $(BOFILES)

fclean : clean
	rm -f $(NAME) $(BNAME)

re : fclean all

.PHONY : clean