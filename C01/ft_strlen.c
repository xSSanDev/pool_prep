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
int     ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
int main() {
    int result;
    result = ft_strlen("zanassdsdc");
    ft_putnbr(result);
    return(0);
}