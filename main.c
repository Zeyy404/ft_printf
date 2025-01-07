#include <stdio.h>
#include "ft_printf.h"

int main()
{
    ft_printf("%+09d", 10000);
    // ft_printf("%p\np%p\n%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
    // printf("%p\np%p\n%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
    // ft_printf("%1s, %1s, %1s, %1s", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
    //printf("%1s, %1s, %1s, %1s", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
    //ft_printf("%0+100d, %+100d, %+100d, %+100d, %+100d, %+100d, %+100d, %+100d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
    // printf("%0+100d, %+100d, %+100d, %+100d, %+100d, %+100d, %+100d, %+100d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
    // ft_printf("%-9u\n", 0);
    // printf("%-9u", 0);
    // printf("%d", printf("%.d", 0));
    // ft_printf("%+d", 42);
    // printf("%d", ft_printf("%.d", 0));
    // ft_printf("\n");
    // printf("%d", ft_printf("%s", "Hello  "));
    // printf("\n");
    // ft_printf("%d", ft_printf("%s", "Hello  "));
    // printf("\n");
    // ft_printf("%d", 42);
    // printf("\n");
    // ft_printf("Hello %%\n");          // Should print: "Hello %"
    // ft_printf("Hello %k\n");          // Should print: "Hello %k"
    // ft_printf("Hello %s\n", "World"); // Should print: "Hello World"
    // printf("%%%s", "Hello");
    // printf("\n");
    // ft_printf("%%%s", "Hello");
    // ft_printf("\n");
    // ft_printf("Hello\nWorld\n");
    return (0);
}