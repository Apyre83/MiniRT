/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:00:17 by lfresnay          #+#    #+#             */
/*   Updated: 2023/01/20 08:43:39 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// Partie 1
int				ft_isalpha(int c);
int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_tolower(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strlen(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
long long int	ft_atoi(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s);

// Partie 2
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(long long int n);
char			*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void			ft_striteri(char *s, void (*f) (unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

// Bonus

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del) (void *));
void			ft_lstclear(t_list **lst, void (*del) (void *));
void			ft_lstiter(t_list *lst, void (*f) (void *));
t_list			*ft_lstmap(t_list *lst, void *(*f) (void *),
					void (*del) (void *));

//GNL
char			*ft_substr_wcheck(char const *s,
					unsigned int start, size_t len);
char			*ft_nb_read_not(char *buffer, char *stock, int nb_read);
char			*ft_read_buffer(int fd, char *stock);
char			*ft_split_line(char *line);
char			*get_next_line(int fd);
int				ft_is_in(char *buffer, char c);

//Ft_printf
typedef struct s_param
{
	int	is_active;
	int	value;
}	t_param;

typedef struct s_options
{
	int		sign_blank;
	int		sign_plus;
	int		left_justify;
	int		hex_prefix;
	int		zero_padded;
	t_param	*precision;
	t_param	*min_width;
}	t_options;

char			*ft_itoa_ull(unsigned long long nbr);
char			*ft_itoa_u(unsigned int nbr);
void			ft_str_toupper(char *str);
char			*ft_printf_char(char c);
char			*ft_printf_charptr(char *word);
char			*ft_printf_ptr(unsigned long long ptr);
char			*ft_printf_nbr(int nbr);
char			*ft_printf_unsigned(unsigned int nbr);
char			*ft_printf_hexa_low(unsigned int nbr);
char			*ft_printf_hexa_upp(unsigned int nbr);
char			*ft_printf_percent(void);
int				ft_printf(const char *str, ...);
int				ft_printf_options_char(char *str, t_options *options);
int				ft_printf_options_str(char *str, t_options *options);
int				ft_printf_options_hexa_low(char *str, t_options *options);
int				ft_printf_options_hexa_upp(char *str, t_options *options);
int				ft_printf_options_ptr(char *str, t_options *options);
int				ft_printf_options_unsigned(char *str, t_options *options);
int				ft_printf_options_int(char *str, t_options *options);
int				ft_printf_options_percent(char *str, t_options *options);
int				ft_printf_unique_char(char c);
int				ft_u_size(unsigned int nbr);
char			*ft_init_temp_width(char *str, t_options *options);
char			*ft_init_temp2_width(char *str, t_options *options);
char			*ft_init_temp_width_low(char *str, t_options *options);
char			*ft_init_temp2_width_low(char *str, t_options *options);
char			*ft_init_temp_width_upp(char *str, t_options *options);
char			*ft_init_temp2_width_upp(char *str, t_options *options);
char			*ft_init_temp_precision(char *str);
char			*ft_init_temp2_precision(char *str);
void			ft_free_options(t_options *options);
int				get_min_width(const char *str, t_options *options);
int				get_precision(const char *str, t_options *options);

t_options		*init_options(void);
t_param			*init_param(void);
t_options		*reset_options(t_options *old);

char			*add_suffix(char *str, char *suffix);
char			*add_prefix(char *str, char *prefix);

#endif
