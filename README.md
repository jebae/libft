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

## file

```c
char *get_file_content(int fd);
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
