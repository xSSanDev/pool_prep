#include <unistd.h>

void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nb)
{
    if(nb < 0)
    {
        ft_putchar('-');
        nb =- nb;
    }
    if(nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0');
}
int     ft_strlen(char *str)
{
    unsigned int    i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int    i;

    i = 0;
    if (size > 0)
    {
        while (src[i] != '\0' && i < (size - 1))
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return (ft_strlen(src));
}
void    ft_putstr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
int main()
{
    char src[] = "hi am anass";
    char dest[15];
    int result;
    result = ft_strlcpy(dest, src, 12);
    ft_putstr("the source is : ");
    ft_putstr(src);
    ft_putchar('\n');
    ft_putstr("the destination : ");
    ft_putstr(dest);
    ft_putchar('\n');
    ft_putstr("the size : ");
    ft_putnbr(result);
    ft_putchar('\n');
    return 0;
}