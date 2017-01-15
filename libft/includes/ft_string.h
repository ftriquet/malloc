/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 06:21:31 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/30 15:46:19 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <string.h>

size_t	ft_tablen(char **t);

int		ft_empty_string(const char *s);

void	ft_freetab(char **tab);

int		ft_tabsize(void **t);

void	ft_strclr(char *s);

void	ft_strdel(char **as);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *s);

char	*ft_strnew(size_t size);

char	*ft_strtrim(const char *s);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	**ft_strsplit(const char *s, char c);

char	*ft_strsub(const char *s, unsigned int start, size_t len);

void	ft_strreplace(char *str, char old, char new);

char	*ft_strrchr(const char *s, int c);

char	*ft_strnstr(const char *s1, const char *s2, size_t n);

size_t	ft_strnlen(const char *s, size_t max);

int		ft_strnequ(const char *s1, const char *s2, size_t n);

char	*ft_strncpy(char *dst, const char *src, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strncat(char *s1, const char *s2, size_t n);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

char	*ft_strmap(char const *s, char (*f)(char));

size_t	ft_strlcat(char *dest, char const *src, size_t n);

char	*ft_strjoin(const char *s1, const char *s2);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_striter(char *s, void (*f)(char *));

int		ft_strequ(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strstr(const char *s1, const char *s2);

char	*ft_strcat(char *s1, const char *s2);

int		ft_get_index(char *str, char c);

int		ft_match(char *string, char *regex);

int		ft_insert_string(char **str, int beg, int end, char *insert);

int		ft_str_replace(char **str, char *search, char *replace);

#endif
