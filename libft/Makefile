# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlamarre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/30 12:46:14 by mlamarre          #+#    #+#              #
#    Updated: 2016/12/22 08:31:50 by mlamarre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRCS =	ft_bzero.c \
		ft_memalloc.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strsub.c \

OBJS =	ft_bzero.o \
		ft_memalloc.o \
		ft_strcat.o \
		ft_strchr.o \
		ft_strcpy.o \
		ft_strdup.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_strnew.o \
		ft_strsub.o \

HEAD =	includes/libft.h

all:	$(NAME)

$(NAME):
		gcc -c -Wall -Werror -Wextra $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: clean
	  	rm -rf $(OBJS)
