/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:11:55 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/07 22:46:28 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../includes/libft.h"

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *line, char *buffer);
char	*ft_strjoinbuff(char *s1, char const *buff);
char	*ft_takeline(char *line, char *buffer);
char	*ft_clearfree(char **buffer, char *line);

// char	*ft_substr(char const *s, unsigned int start, size_t len);
// size_t	ft_strlen(const char *s);
// char	*ft_strchr(const char *s, int c);
// void	*ft_memmove(void *dest, const void *src, size_t n);
// void	ft_bzero(void *s, size_t n);

#endif
