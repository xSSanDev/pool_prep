#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putstr(char *str)
{
    int     i;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
int     main(int argc, char *argv[])
{
    (void)argc; // tell the compiler you know argc is unused
    ft_putstr(argv[0]);
    ft_putchar('\n');
    return (0);
}
