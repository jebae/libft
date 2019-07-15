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

# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

# compiler
CC = gcc

# lib name
NAME = libft.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)

# srcs
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
	ft_atof.c\
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
	ft_swap.c\
	put_color_str.c\
	ft_lstiter_with_arg.c\
	get_file_content.c\
	queue_init.c\
	queue_push.c\
	queue_pop.c\
	btree_create_node.c\
	btree_insert_data.c\
	btree_bfs.c\
	btree_apply_inorder.c\
	btree_apply_postorder.c\
	btree_delone.c\
	btree_del.c\
	btree_search_one.c\
	btree_remove_if.c\
	btree_foreach.c\
	btree_foreach_with_arg.c\
	set_init.c\
	set_add.c\
	set_remove_if.c\
	set_del.c\
	set_foreach.c\
	set_foreach_with_arg.c\
	set_length.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# compile objs
$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/libft.h $(INCDIR)/get_next_line.h
	@printf "$(KGRN)[libft]$(KNRM) compile $<\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))

# build
all : $(NAME)

$(NAME) : pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

pre_build :
	@printf "$(KGRN)[libft] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[libft] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re
