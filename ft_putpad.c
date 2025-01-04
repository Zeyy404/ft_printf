#include "ft_printf.h"

int ft_putpad(int count, char padchr)
{
    int i;
    
    i = 0;
    while (i < count)
    {
        write(1, &padchr, 1);
        i++;
    }
    return (i);
}