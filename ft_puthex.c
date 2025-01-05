/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:38:58 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/06 00:58:48 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_calcpad_width(int len, t_format *fmt)
{
	int pad_width;

	if (fmt->precision > len)
    	pad_width = fmt->width - fmt->precision;
	else
    	pad_width = fmt->width - len;
	if (pad_width < 0)
		pad_width = 0;
	return (pad_width);
}
int	printhex(char *buffer, int len, t_format *fmt)
{
	int	count;
	int pad_width;

	count = 0;
	pad_width = ft_calcpad_width(len, fmt);
	if (!fmt->flag_minus)
	{
        if (fmt->flag_zero && fmt->precision == -1)
			count += ft_putpad(pad_width, '0');
		else
			count += ft_putpad(pad_width, ' ');
	}
	if (fmt->flag_hash && fmt->specifier == 'x')
		count += write(1, "0x", 2);
	else if (fmt->flag_hash && fmt->specifier == 'X')
		count += write(1, "0X", 2);
	if (fmt->precision > len)
        count += ft_putpad(fmt->precision - len, '0');
  	while (--len >= 0)
    	count += write(1, &buffer[len], 1);
	if (fmt->flag_minus)
        count += ft_putpad(pad_width, ' ');
    return (count);
}
int ft_puthex(va_list args, t_format *fmt)
{
    unsigned int n;
    char buffer[16];
    int len;
    int remainder;

    n = va_arg(args, unsigned int);
    if (n == 0)
	{
		if (fmt->precision != 0)
        	return (write(1, "0", 1));
		return (0);
	}
	len = 0;
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
    return (printhex(buffer, len, fmt));
}
