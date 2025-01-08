/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:38:58 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/08 21:28:09 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhex(char *buffer, int len, int is_zero, t_format *fmt)
{
	int	count;
	int	pad_width;

	count = 0;
	if (fmt->flag_hash && !is_zero)
		pad_width = set_pad_width(len + 2, fmt);
	else
		pad_width = set_pad_width(len, fmt);
	if (!fmt->flag_minus && !(fmt->flag_zero && fmt->precision == -1))
	{
		if (fmt->flag_hash)
			count += putpad(pad_width - 2, ' ');
		else
			count += putpad(pad_width, ' ');
	}
	if (fmt->flag_hash && fmt->specifier == 'x' && !is_zero)
		count += write(1, "0x", 2);
	else if (fmt->flag_hash && fmt->specifier == 'X' && !is_zero)
		count += write(1, "0X", 2);
	if (!fmt->flag_minus && fmt->flag_zero && fmt->precision == -1)
		count += putpad(pad_width, '0');
	if (fmt->precision > len)
		count += putpad(fmt->precision - len, '0');
	while (--len >= 0)
		count += write(1, &buffer[len], 1);
	if (fmt->flag_minus)
		count += putpad(pad_width, ' ');
	return (count);
}

int	fill_buffer(char *buffer, unsigned long n, t_format *fmt)
{
	int	len;
	int	remainder;

	len = 0;
	remainder = 0;
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			buffer[len++] = remainder + '0';
		else if (fmt->specifier == 'x')
			buffer[len++] = remainder - 10 + 'a';
		else if (fmt->specifier == 'X')
			buffer[len++] = remainder - 10 + 'A';
		n /= 16;
	}
	return (len);
}

int	ft_puthex(va_list args, t_format *fmt)
{
	unsigned long	n;
	char			buffer[16];
	int				len;
	int				is_zero;

	n = (unsigned long)va_arg(args, unsigned int);
	is_zero = 0;
	if (n == 0)
	{
		is_zero = 1;
		if (fmt->precision != 0)
			return (printhex("0", 1, is_zero, fmt));
		return (printhex("", 0, is_zero, fmt));
	}
	len = fill_buffer(buffer, n, fmt);
	return (printhex(buffer, len, is_zero, fmt));
}
