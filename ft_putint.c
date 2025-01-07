/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:40:18 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/07 22:41:41 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printint(char *buffer, int len, int is_neg, t_format *fmt)
{
	int	count;
	int	pad_width;

	count = 0;
	pad_width = ft_calcpad_width(len, fmt);
	if (fmt->flag_plus || fmt->flag_space)
		pad_width -= 1;
	if (!fmt->flag_minus)
	{
		if (fmt->flag_zero && fmt->precision == -1)
		{
			if (is_neg)
				count += write(1, "-", 1);
			else if (fmt->flag_plus)
				count += write(1, "+", 1);
			count += ft_putpad(pad_width, '0');
		}
		else
			count += ft_putpad(pad_width, ' ');
	}
	if (fmt->flag_plus && buffer[0] != '-' && !fmt->flag_zero)
		count += write(1, "+", 1);
	else if (fmt->flag_space)
		count += write(1, " ", 1);
	if (fmt->precision > len)
		count += ft_putpad(fmt->precision - len, '0');
	if (is_neg)
		count += write(1, "-", 1);
	while (--len >= 0)
		count += write(1, &buffer[len], 1);
	if (fmt->flag_minus)
		count += ft_putpad(pad_width, ' ');
	return (count);
}

int	ft_putint(va_list args, t_format *fmt)
{
	long	num;
	int		len;
	int		is_neg;
	char	buffer[12];

	num = (long)va_arg(args, int);
	is_neg = 0;
	if (num == 0)
	{
		if (fmt->precision == 0)
			return (ft_putpad(ft_calcpad_width(0, fmt), ' '));
		return (printint("0", 1, is_neg, fmt));
	}
	if (num < 0)
	{
		is_neg = 1;
		num = -num;
	}
	len = 0;
	while (num > 0)
	{
		buffer[len++] = (num % 10) + '0';
		num /= 10;
	}
	return (printint(buffer, len, is_neg, fmt));
}
