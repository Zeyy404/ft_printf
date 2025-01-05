#include "ft_printf.h"

int	ft_precision_nbr(int len, t_format *fmt)
{
	if (fmt->precision > len)
        return ft_putpad(fmt->precision - len, '0');
    return 0;
}
