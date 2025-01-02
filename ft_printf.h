/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:15 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/02 20:39:22 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
	int		width;
	int		precision;
	char	specifier;
	int		(*f)(va_list, struct s_format *);
}			t_format;

int			ft_printf(const char *format, ...);
int			ft_putchr(va_list args, t_format *fmt);
int			ft_putstr(va_list args, t_format *fmt);
int			ft_putptr(va_list args, t_format *fmt);
int			ft_putint(va_list args, t_format *fmt);
int			ft_putuint(va_list args, t_format *fmt);
int			ft_puthex(va_list args, t_format *fmt);
int			ft_putuphex(va_list args, t_format *fmt);
int			ft_putpct(va_list args, t_format *fmt);

#endif