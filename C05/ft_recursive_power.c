#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nbr)
{
    if(nbr >= 10)
        ft_putnbr(nbr / 10);
    ft_putchar((nbr % 10) + '0');
}
int     ft_recursive_power(int nb, int power)
{
    if(power < 0)
        return 0;
    if(power == 0)
        return 1;
    if(power > 0)
        return (nb * ft_recursive_power(nb, power - 1));
}
int main()
{
    ft_putnbr(ft_recursive_power(10,3));
    return (0);
}