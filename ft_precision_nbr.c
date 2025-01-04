#include "ft_printf.h"

int	ft_precision_nbr(int len, t_format *fmt)
{
	int count;

	count = 0;
	if (fmt->width > fmt->precision)
	{
		if (fmt->flag_minus)
		{
			count += ft_putpad((fmt->precision), '0');
		}
	}
	else
		count += ft_putpad((fmt->precision), '0');
	return (count);
}
