/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:40:25 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/02 20:40:26 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putuint(va_list args, t_format *fmt)
{
    unsigned int num;
    int count;
    int len;
    char buffer[12];

    num = va_arg(args, unsigned int);
    count = 0;
    if (num == 0)
        return (write(1, "0", 1));
    len = 0;
    while (num > 0)
    {
        buffer[len++] = (num % 10) + '0';
        num /= 10;
    }
    while (len--)
        count += write(1, &buffer[len], 1);

    return (count);
}
