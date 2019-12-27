# libft

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/174af4658a6d47f38a4c890a29dcee29)](https://www.codacy.com/manual/jebae/libft?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jebae/libft&amp;utm_campaign=Badge_Grade)

C library **libft** is made to use functions of memory, string, data structure instead of functions in `stdlib.h` and `string.h`.

<br><br>

## Installation

```c
make
```

<br><br>

## Features

### memory

```c
void *ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memccpy(void *dst, const void *src, int c, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memalloc(size_t size);
void ft_memdel(void **ap);
void ft_swap(void *p1, void *p2, size_t size);
void ft_memnegate(unsigned char *mem, size_t size);
```

<br><br>

## string

```c
size_t ft_strlen(const char *str);
char *ft_strdup(const char *s1);
char *ft_strcpy(char *dst, const char *src);
char *ft_strncpy(char *dst, const char *src, size_t len);
char *ft_strcat(char *s1, const char *s2);
char *ft_strncat(char *s1, const char *s2, size_t n);
size_t ft_strlcat(char *dst, const char *src, size_t size);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_isdigit(int c);
int ft_atoi(const char *str);
double ft_atof(const char *str);
int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strnew(size_t size);
void ft_strdel(char **as);
void ft_strclr(char *s);
void ft_striter(char *s, void (*f)(char *as));
void ft_striteri(char *s, void (*f)(unsigned int i, char *as));
char *ft_strmap(const char *s, char (*f)(char ch));
char *ft_strmapi(
	const char *s,
	char (*f)(unsigned int i, char ch)
);
int ft_strequ(const char *s1, const char *s2);
int ft_strnequ(const char *s1, const char *s2, size_t n);
char *ft_strsub(const char *s, unsigned int start, size_t len);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strtrim(const char *s);
char **ft_strsplit(const char *s, char c);
char *ft_itoa(int n);
char *ft_boyer_moore(const char *text, const char *pat);
char *ft_strstr(const char *haystack, const char *needle);
char *ft_strnstr(
	const char *haystack,
	const char *needle,
	size_t len
);
int ft_hexatoi(const char *str);
int ft_ishexdigit(int c);
int ft_iswhitespace(char ch);
void ft_to_utf8(wchar_t wch, char *utf8);
int ft_utf8_byte_len(char *utf8);
```

<br><br>

## sys IO

```c
void ft_putchar_fd(char c, int fd);
void ft_putchar(char c);
void ft_putstr(const char *s);
void ft_putendl(const char *s);
void ft_putnbr(int n);
void ft_putstr_fd(const char *s, int fd);
void ft_putendl_fd(const char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void put_color_str(const char *color, const char *s);
```

<br><br>

## linked list

```c
t_list *ft_lstnew(const void *content, size_t content_size);
void ft_lstdelone(
	t_list **alst,
	void (*del)(void *content, size_t content_size)
);
void ft_lstdel(
	t_list **alst,
	void (*del)(void *content, size_t content_size)
);
void ft_lstadd(t_list **alst, t_list *n);
void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void ft_sorted_lstadd(
	t_list **alst,
	t_list *n,
	int (*compare)(t_list *, t_list *)
);
t_list *ft_sorted_lstpop(t_list **alst);
void ft_lstsort(
	t_list **alst,
	int (*compare)(t_list *, t_list *)
);
void ft_lstrev(t_list **alst);
size_t ft_lstlen(t_list *lst);
void ft_lstiter_with_arg(
	t_list *lst,
	void (*f)(t_list *elem, void *arg),
	void *arg
);
```

<br><br>

## file

```c
char *get_file_content(int fd);
```

<br><br>

## queue

```c
t_queue queue_init(void);
void queue_push(
	t_queue *queue,
	void *content,
	size_t content_size
);
void *queue_pop(t_queue *queue);
```

<br><br>

## binary tree

```c
t_btree *btree_create_node(void *content, size_t content_size);
void btree_insert_data(
	t_btree **root,
	void *content,
	size_t content_size,
	int (*cmpf)(void *, void *)
);
void btree_bfs(t_btree *root, void (*f)(void *content));
void btree_apply_inorder(
	t_btree *root,
	void (*applyf)(void *)
);
void btree_apply_postorder(
	t_btree *root,
	void (*applyf)(void *)
);
void btree_delone(t_btree **node, void (*del)(void *content));
void btree_del(t_btree **root, void (*del)(void *content));
void *btree_search_one(
	t_btree *root,
	void *p_data,
	int (*cmpf)(void *, void *)
);
void btree_remove_if(
	t_btree **root,
	void *p_data,
	int (*cmpf)(void *, void *)
);
void btree_foreach(
	t_btree *root,
	void (*f)(void *content)
);
void btree_foreach_with_arg(
	t_btree *root,
	void *arg,
	void (*f)(void *content, void *arg)
);
```

<br><br>

## set

```c
t_set set_init(int (*cmpf)(void *, void *));
void set_add(
	t_set *set,
	void *content,
	size_t content_size
);
void set_remove_if(
	t_set *set,
	void *p_data,
	int (*cmpf)(void *, void *)
);
void set_del(t_set *set);
void set_foreach(t_set *set, void (*f)(void *content));
void set_foreach_with_arg(
	t_set *set,
	void *arg,
	void (*f)(void *content, void *arg)
);
size_t set_length(t_set *set);
```

<br><br>

## math

```c
long long ft_powd(long long num, size_t e);
unsigned long long ft_powud(unsigned long long num, size_t e);
size_t ft_bit_reverse(size_t x, size_t num_bits);
unsigned int ft_int_log2(size_t num);
void ft_extract_double(
	double num,
	short *exponent,
	unsigned long long *mantissa
);
int ft_is_inf(double num);
int ft_is_nan(double num);
void ft_extract_ldouble(
	long double num,
	short *exponent,
	unsigned long long *mantissa
);
int ft_is_inf_l(long double num);
int ft_is_nan_l(long double num);
long long ft_max_int(long long a, long long b);
long long ft_min_int(long long a, long long b);
```