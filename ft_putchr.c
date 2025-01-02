/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:33 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/02 20:39:40 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(va_list args, t_format *fmt)
{
	char	c;
	int		count;
	int		pad;

	c = (char)va_arg(args, int);
	count = 0;
	if (fmt->width > 1)
		pad = fmt->width - 1;
	else
		pad = 0;
	if (fmt->flag_minus)
	{
		count += write(1, &c, 1);
		while (pad-- > 0)
			count += write(1, " ", 1);
	}
	else
	{
		while (pad-- > 0)
			count += write(1, " ", 1);
		count += write(1, &c, 1);
	}
	return (count);
}
