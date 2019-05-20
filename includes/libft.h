/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:26:04 by jebae             #+#    #+#             */
/*   Updated: 2019/05/20 16:57:29 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define LONG_LIMIT 0x7FFFFFFFFFFFFFFF
# define CHARACTER_TABLE_SIZE 256
# define MAX(a, b) ((a) > (b)) ? (a) : (b)
# define ABS(N) ((N < 0) ? -(N) : (N))
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KNRM "\x1B[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *s1);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_isdigit(int c);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *as));

void				ft_striteri(char *s, void (*f)(unsigned int i, char *as));

char				*ft_strmap(const char *s, char (*f)(char ch));

char				*ft_strmapi(const char *s,\
		char (*f)(unsigned int i, char ch));

int					ft_strequ(const char *s1, const char *s2);

int					ft_strnequ(const char *s1, const char *s2, size_t n);

char				*ft_strsub(const char *s, unsigned int start, size_t len);

char				*ft_strjoin(const char *s1, const char *s2);

char				*ft_strtrim(const char *s);

char				**ft_strsplit(const char *s, char c);

char				*ft_itoa(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putchar(char c);

void				ft_putstr(const char *s);

void				ft_putendl(const char *s);

void				ft_putnbr(int n);

void				ft_putstr_fd(const char *s, int fd);

void				ft_putendl_fd(const char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(const void *content, size_t content_size);

void				ft_lstdelone(t_list **alst,\
		void (*del)(void *content, size_t content_size));

void				ft_lstdel(t_list **alst,\
		void (*del)(void *content, size_t content_size));

void				ft_lstadd(t_list **alst, t_list *n);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char				*ft_boyer_moore(const char *text, const char *pat);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnstr(const char *haystack,\
		const char *needle, size_t len);

void				ft_sorted_lstadd(t_list **alst, t_list *n,\
		int (*compare)(t_list *, t_list *));

t_list				*ft_sorted_lstpop(t_list **alst);

void				ft_lstsort(t_list **alst,\
		int (*compare)(t_list *, t_list *));

void				ft_lstrev(t_list **alst);

int					ft_hexatoi(const char *str);

int					ft_ishexdigit(int c);

size_t				ft_lstlen(t_list *lst);

int					ft_iswhitespace(char ch);

#endif
