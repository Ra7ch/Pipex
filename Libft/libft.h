/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raitmous <raitmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:19:18 by raitmous          #+#    #+#             */
/*   Updated: 2023/02/04 22:47:17 by raitmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

long long			ft_atoi(char *str);
char				*ft_strrchr(const char *str, int c);
void				*ft_bzero(void *dest, size_t size);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t l);
int					ft_memcmp(void *s1, void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				*ft_memset(void *dest, int c, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *str1, const char *str2,
						size_t count);
char				*ft_strnstr(const char *hay, const char *ne, size_t l);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(int));
void				ft_lstclear(t_list **lst, void (*del)(int));
void				ft_lstiter(t_list *lst, void (*f)(int));
t_list				*ft_lstmap(t_list *lst, int *(*f)(int), void (*del)(int));

#endif