/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:40:11 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/07 18:18:52 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printptr(char *buffer, int len, t_format *fmt)
{
	int	count;
	int	pad_width;

	count = 0;
	pad_width = ft_calcpad_width(len, fmt);
	if (!fmt->flag_minus)
	{
		if (fmt->flag_zero)
			count += ft_putpad(pad_width, '0');
		else
			count += ft_putpad(pad_width, ' ');
	}
	while (--len >= 0)
		count += write(1, &buffer[len], 1);
	if (fmt->flag_minus)
		count += ft_putpad(pad_width, ' ');
	return (count);
}

int	ft_putptr(va_list args, t_format *fmt)
{
	unsigned long	ptr;
	char			buffer[18];
	int				count;
	int				len;
	int				remainder;

	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		return (write(1, "0x0", 3));
	count = write(1, "0x", 2);
	len = 0;
	while (ptr > 0)
	{
		remainder = ptr % 16;
		if (remainder < 10)
			buffer[len++] = remainder + '0';
		else
			buffer[len++] = remainder - 10 + 'a';
		ptr /= 16;
	}
	return (count + printptr(buffer, len, fmt));
}
