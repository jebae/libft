# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebae <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 15:51:53 by jebae             #+#    #+#              #
#    Updated: 2019/04/05 16:44:55 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.SILENT :

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_memset.c srcs/ft_bzero.c srcs/ft_memcpy.c\
	   srcs/ft_memccpy.c srcs/ft_memmove.c srcs/ft_memchr.c\
	   srcs/ft_memcmp.c srcs/ft_strlen.c srcs/ft_strdup.c\
	   srcs/ft_strcpy.c srcs/ft_strncpy.c srcs/ft_strcat.c\
	   srcs/ft_strncat.c srcs/ft_strlcat.c srcs/ft_strchr.c\
	   srcs/ft_strrchr.c srcs/ft_strcmp.c srcs/ft_strncmp.c\
	   srcs/ft_isdigit.c srcs/ft_atoi.c srcs/ft_isalpha.c\
	   srcs/ft_isalnum.c

INCLUDES = ./includes

OBJS = ft_memset.o ft_bzero.o ft_memcpy.o\
	   ft_memccpy.o ft_memmove.o ft_memchr.o\
	   ft_memcmp.o ft_strlen.o ft_strdup.o\
	   ft_strcpy.o ft_strncpy.o ft_strcat.o\
	   ft_strncat.o ft_strlcat.o ft_strchr.o\
	   ft_strrchr.o ft_strcmp.o ft_strncmp.o\
	   ft_isdigit.o ft_atoi.o ft_isalpha.o\
	   ft_isalnum.o

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
