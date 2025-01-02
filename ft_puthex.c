/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:38:58 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/02 20:39:00 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(va_list args, t_format *fmt)
{
    unsigned int n;
    int count;
    char buffer[16];
    int len;
    int remainder;

    n = va_arg(args, unsigned int);
    if (n == 0)
        return (write(1, "0", 1));
    count = 0;
    len = 0;
    while (n > 0)
    {
        remainder = n % 16;
        if (remainder < 10)
            buffer[len++] = remainder + '0';
        else if (remainder > 10 && fmt->specifier == 'x')
            buffer[len++] = remainder - 10 + 'a';
        else if (remainder > 10 && fmt->specifier == 'X')
            buffer[len++] = remainder - 10 + 'A';
        n /= 16;
    }
    while (--len >= 0)
        count += write(1, &buffer[len], 1);

    return (count);
}
