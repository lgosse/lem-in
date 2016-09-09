/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:06:03 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/07 14:21:23 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_parse
{
	int				nb_arg;
	int				opt;
	t_list			*args;
}					t_parse;

int					ft_printf(const char *fmt, ...);
int					get_next_line(int fd, char **line);

int					ft_abs(int nb);
int					ft_pow(int nb, int power);
void				ft_tabdel(void **todel);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strisalnum(char *str);
int					ft_isalnum(int c);
int					ft_strisalpha(char *str);
int					ft_isalpha(int c);
int					ft_strisdigit(char *str);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_iswhitespace(char c);
int					ft_strisint(char *nbr);

void				ft_strupcase(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_n_free(char *s1, char *s2);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strncpy(char *dst, char const *src, size_t n);
char				*ft_strndup(char *str, int n);
char				*ft_strdup(const char *s1);
char				**ft_tabstrdup(char **tab);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_checkstr(char *chars, char *cmp);
char				*ft_strchr(const char *s, int c);
char				*ft_strnchr(const char *s, int c, int n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
size_t				ft_count(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
int					ft_wordlen(char *str, char c);
size_t				ft_strlen(char const *s);
size_t				ft_linelen(char const *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				*ft_ltoa_base(long n, int base);
char				*ft_ultoa_base(unsigned long n, int base);
int					ft_get_nb_length(int n, int base);
int					ft_atoi(const char *str);

void				ft_swap(void **ptr1, void **ptr2);
void				ft_swap_int(int *i1, int *i2);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_puttab(char **tab);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
char				*ft_realloc_char(char *ptr, size_t size);
void				*ft_realloc(void *ptr, int sizeofptr, int size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstdup(t_list *src);
void				ft_lstdelfirst(t_list **alst);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelbyfunc(t_list **alst, void (*del)(void *content));
void				ft_lstdel(t_list **list);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddtail(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_nbrsplit(t_list **alst, char *str);

t_parse				*ft_parse(int ac, char **av, char *opt);
void				ft_free_parse(t_parse *parse);
t_list				*ft_parse_file(char *filename, char *chars);

#endif
