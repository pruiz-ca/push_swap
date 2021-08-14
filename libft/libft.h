/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:41:47 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:52:39 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <math.h>
# include <inttypes.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct s_color
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
	unsigned int		hex;
}						t_color;

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *str, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *str, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *src);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char		*ft_strdup_limit(const char *src, int end);
char		*ft_strupcase(char *str);
char		*ft_itoa_base(int n, unsigned long base);
char		*ft_itoa_base_llu(unsigned long n, unsigned long base);
char		*ft_itoa_base_uint(unsigned int n, unsigned int base);
int			ft_isspace(int c);
char		**ft_split_isspace(char const *s, int *n_words);
double		ft_power(double num, double pow);
double		ft_atof(const char *str);
void		ft_freetab(char **tab);
void		ft_swap_double(double *s1, double *s2);
int			ft_ternary(int cond, int true_val, int false_val);
intmax_t	ft_atol(const char *str);

int			get_next_line(int fd, char **line);

t_vector	ft_vecsum(t_vector v1, t_vector v2);
t_vector	ft_vecsub(t_vector plus, t_vector minus);
double		ft_vecdot(t_vector v1, t_vector v2);
double		ft_veclen(t_vector v);
t_vector	ft_vecsca(t_vector v, double s);
t_vector	ft_vecscasub(t_vector v, double s);
double		ft_degtorad(double	angle);
t_vector	ft_vecnorm(t_vector v);
t_vector	ft_vecx(t_vector v1, t_vector v2);
t_vector	ft_vecxmat(t_vector mat[4], t_vector v);
t_vector	ft_vecscadiv(t_vector v, double s);
t_color		ft_vcolorsum(t_color *c1, t_color *c2);

#endif
