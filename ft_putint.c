/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:40:18 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/06 01:19:19 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printint(char *buffer, int len, t_format *fmt)
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
	if (fmt->precision > len)
        count += ft_putpad(fmt->precision - len, '0');
  	while (--len >= 0)
    	count += write(1, &buffer[len], 1);
	if (fmt->flag_minus)
        count += ft_putpad(pad_width, ' ');
    return (count);
}

int ft_putint(va_list args, t_format *fmt)
{
    int num;
    int count;
    int len;
    char buffer[12];

    num = va_arg(args, int);
    count = 0;
    if (num == 0 && fmt->precision == 0)
        return (0);
    if (num < 0)
    {
        count += write(1, "-", 1);
        num = -num;
    }
    else if (fmt->flag_plus)
        count += write(1, "+", 1);
    else if (fmt->flag_space)
        count += write(1, " ", 1);
    len = 0;
    while (num > 0)
    {
        buffer[len++] = (num % 10) + '0';
        num /= 10;
    }
    return (count + printint(buffer, len, fmt));
}
