/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:40:25 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/07 18:11:49 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printuint(char *buffer, int len, t_format *fmt)
{
	int	count;
	int	pad_width;

	count = 0;
	pad_width = ft_calcpad_width(len, fmt);
	if (!fmt->flag_minus)
	{
		if (fmt->flag_zero && fmt->precision == -1)
			count += ft_putpad(pad_width, '0');
		else
			count += ft_putpad(pad_width, ' ');
	}
	if (fmt->precision > len)
		count += ft_putpad(fmt->precision - len, '0');
	while (--len >= 0)
		count += write(1, &buffer[len], 1);
	if (fmt->flag_minus)
		count += ft_putpad(pad_width, ' ');
	return (count);
}

int	ft_putuint(va_list args, t_format *fmt)
{
	unsigned int	num;
	int				len;
	char			buffer[12];

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		if (fmt->precision == 0)
			return (0);
		return (printuint("0", 1, fmt));
	}
	len = 0;
	while (num > 0)
	{
		buffer[len++] = (num % 10) + '0';
		num /= 10;
	}
	return (printuint(buffer, len, fmt));
}
