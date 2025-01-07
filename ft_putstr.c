/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:48 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/08 00:09:00 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list args, t_format *fmt)
{
	int		count;
	char	*str;
	int		pad_width;
	int		precision;

	str = va_arg(args, char *);
	count = 0;
	if (!str)
		str = "(null)";
	if (fmt->precision > 0 && fmt->precision < (int)ft_strlen(str))
		precision = fmt->precision;
	else
		precision = ft_strlen(str);
	pad_width = set_pad_width(precision, fmt);
	if (!fmt->flag_minus)
		putpad(pad_width, ' ');
	count += write(1, str, precision);
	if (fmt->flag_minus)
		putpad(pad_width, ' ');
	return (count);
}
