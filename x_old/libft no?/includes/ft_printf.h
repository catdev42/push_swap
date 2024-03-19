/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 02:10:52 by myakoven          #+#    #+#             */
/*   Updated: 2024/02/07 22:42:10 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include "./libft/libft.h"
# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
int		ft_checkcase(va_list args, const char format);

int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnum(int n);

int		ft_printuns(unsigned int u);

int		ft_printptr(uintptr_t address);
int		ft_printhex(unsigned int num, char format);

int		ft_print_it_hex(unsigned int num, char format);
// int		ft_strlen(const char *s);
char	*ft_uitoa_printf(unsigned int u);
int		ft_unslen(unsigned int u);
int		ft_print_it(uintptr_t address);
// char	*ft_itoa(int n);
char	*ft_itoa_printf(int n);

#endif
