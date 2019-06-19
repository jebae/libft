# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebae <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 18:09:31 by jebae             #+#    #+#              #
#    Updated: 2019/06/18 18:33:56 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\e[1;31m%s\e[0m
GRN=\e[1;32m%s\e[0m
YEL=\e[1;33m%s\e[0m

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

INCLUDES = -I ./includes

SRCS = get_next_line.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_isdigit.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstsort.c\
	ft_lstrev.c\
	ft_strstr.c\
	ft_boyer_moore.c\
	ft_strnstr.c\
	ft_sorted_lstadd.c\
	ft_sorted_lstpop.c\
	ft_hexatoi.c\
	ft_ishexdigit.c\
	ft_lstlen.c\
	ft_iswhitespace.c\
	put_color_str.c\
	ft_lstiter_with_arg.c\
	get_file_content.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJDIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/libft.h $(INCDIR)/get_next_line.h
	@printf "$(YEL)\n" "-> compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
