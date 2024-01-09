/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 05:43:38 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 02:09:50 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
//printf
# include <errno.h>
# include <string.h>

# define FT_SUCCESS 1
# define FT_ERROR 0
# define FT_FAIL 0
# define FT_PERROR -1
# define FT_CMDUNDEFINED 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//string function
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char	*s, const char *find, size_t slen);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
//memory function
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
//print function
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
//Free function
int		ft_free(void *ptr);
int		ft_freestrarray(char **ptr);
#endif
