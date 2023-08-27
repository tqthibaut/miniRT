/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthibaut <tthibaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:50:28 by tthibaut          #+#    #+#             */
/*   Updated: 2022/04/23 13:50:56 by tthibaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define BUFFER_SIZE 1

int		ft_atoi(char *str);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

int		ft_is_a_double(char *str);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

char	*ft_itoa(int n);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memset(void *b, int c, size_t n);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(char *s, int fd);

char	**ft_split(char const *s, char c);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *str1, const char *str2, size_t n);

char	*ft_strrchr(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_tolower(int c);

int		ft_toupper(int c);

int		is_a_double(char *str);

float	ft_atof(char *s);

double	ft_atodb(char *s);

/******************************************************************************/
/*                                                                            */
/*                           ft_split*.c                                      */
/*                                                                            */
/******************************************************************************/

char	**ft_split_plus(char const *s, char c);

size_t	ft_count_words(char const *s, char c);

int		free_tabs(char **tab);

char	*ft_strjoin_plus(char *s1, char *s2);

char	**ft_fill_row_plus(char **dst, char const *src, char c);

//static char	**ft_free(char const **tab, size_t j);

size_t	ft_splitstrlcpy_plus(char *dst, const char *src, size_t size);

char	**ft_split_tab(char const *s);

char	**ft_fill_row_tab(char **tab, char const *src, char c);
/******************************************************************************/
/*                                                                            */
/*                           Get_Next_Line.c                                  */
/*                                                                            */
/******************************************************************************/
char	*get_next_line(int fd);

char	*ft_strchr_gnl(char *s, int c);

char	*ft_strdup_gnl(char *s1);

char	*ft_cat_str_gnl(char *str, char *buf);

char	*ft_strjoin_gnl(char *s1, char *s2);

size_t	ft_totallen_gnl(char *s1, char *s2);

char	*ft_else_gnl(char *str);

typedef struct cmd_list
{
	char			**arg;
	struct cmd_list	*next;
	struct cmd_list	*prev;
}	t_listtab;

#endif
