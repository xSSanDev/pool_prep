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
    ft_putchar((nb % 10) + '0');
}
int     ft_str_is_numeric(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int main()
{
    char a[10] = "2763523";
    int result;
    result = ft_str_is_numeric(a);
    ft_putnbr(result);
}
