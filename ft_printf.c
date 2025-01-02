/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:39:04 by zsalih            #+#    #+#             */
/*   Updated: 2025/01/02 20:39:06 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format *fmt)
{
	fmt->flag_minus = 0;
	fmt->flag_zero = 0;
	fmt->flag_hash = 0;
	fmt->flag_space = 0;
	fmt->flag_plus = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->specifier = '\0';
	fmt->f = NULL;
}
void	assign_f(t_format *fmt)
{
	if (fmt->specifier == 'c')
		fmt->f = ft_putchr;
	else if (fmt->specifier == 's')
		fmt->f = ft_putstr;
	else if (fmt->specifier == 'p')
		fmt->f = ft_putptr;
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		fmt->f = ft_putint;
	else if (fmt->specifier == 'u')
		fmt->f = ft_putuint;
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		fmt->f = ft_puthex;
	else
		fmt->f = NULL;
}
void	set_flag(const char *format, int *i, t_format *fmt)
{
	if (format[*i] == '-')
		fmt->flag_minus = 1;
	else if (format[*i] == '+')
		fmt->flag_plus = 1;
	else if (format[*i] == '0')
		fmt->flag_zero = 1;
	else if (format[*i] == '#')
		fmt->flag_hash = 1;
	else if (format[*i] == ' ')
		fmt->flag_space = 1;
}
int	parse_format(const char *format, int *i, t_format *fmt)
{
	(*i)++;
	while (format[*i] == '-' || format[*i] == '+' || format[*i] == ' '
		|| format[*i] == '#' || format[*i] == '0')
	{
		set_flag(format, i, fmt);
		(*i)++;
	}
	if (ft_isdigit(format[*i]))
	{
		fmt->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == '.')
	{
		(*i)++;
		if (ft_isdigit(format[*i]))
		{
			fmt->precision = ft_atoi(&format[*i]);
			while (ft_isdigit(format[*i]))
				(*i)++;
		}
		else
			fmt->precision = 0;
	}
}
int	check_spec(const char *format, va_list args, int *i, t_format *fmt)
{
	int	count;

	count = 0;
	if (format[*i + 1] == '%')
	{
		count += write(1, "%", 1);
		(*i) += 2;
		return (count);
	}
	count += parse_format(format, i, fmt);
	fmt->specifier = format[*i];
	assign_f(fmt);
	if (fmt->f)
	{
		count += fmt->f(args, fmt);
		(*i)++;
		return (count);
	}
	if (format[*i] == '%' && format[*i + 1])
		count += write(1, &format[(*i)++], 1);
	else
		(*i)++;
	return (count);
}
int	ft_printf(const char *format, ...)
{
	t_format	*fmt;
	va_list		args;
	int			count;
	int			i;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (-1);
	init_format(fmt);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += check_spec(format, args, &i, fmt);
		else
			count += write(1, &format[i++], 1);
	}
	va_end(args);
	free(fmt);
	return (count);
}
