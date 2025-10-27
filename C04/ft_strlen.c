#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nb)
{
    if(nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}
int     ft_strlen(char *str)
{
    unsigned int    i;
    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
int main()
{
    char a[10] = "Hello anass";
    unsigned int result;
    result = ft_strlen(a);
    ft_putnbr(result);
    return 0;
}
