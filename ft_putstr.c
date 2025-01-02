/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:48 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/02 20:40:00 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list args, t_format *fmt)
{
	int		count;
	char	*str;
	int		pad;

	str = va_arg(args, char *);
	count = 0;
	if (!str)
		str = "(null)";
	if (fmt->width > 1)
		pad = fmt->width - 1;
	else
		pad = 0;
	if (fmt->precision > 0)
		count = fmt->precision;
	if (fmt->flag_minus)
	{
		while (str[count])
			write(1, &str[count++], 1);
		while (pad-- > 0)
			count += write(1, " ", 1);
	}
	else
	{
		while (pad-- > 0)
			count += write(1, " ", 1);
		while (str[count])
			write(1, &str[count++], 1);
	}
	return (count);
}
