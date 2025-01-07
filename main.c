#include <stdio.h>
#include "ft_printf.h"

int main()
{
    printf("%-+5.3d\n", 42);
    ft_printf("% -+5.3d\n", 42);
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