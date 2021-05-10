/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:43:53 by wlakita           #+#    #+#             */
/*   Updated: 2021/04/23 17:14:02 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
int		read_from_fd(char **rmdr, char **p_n, int fd);
int		f_n_find(char **line, char **p_n, char **rmdr);
int		f_last(char **line, char **rmdr);
#endif
