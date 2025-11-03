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
int     ft_iterative_power(int nb, int power)
{
    int     result;
    if(power < 0)
        return 0;
    if(power == 0)
        return 1;

    result = 1;
    while(power > 0)
    {
        result = result * nb;
        power --;
    }
    return(result);
}
int main()
{
    ft_putnbr(ft_iterative_power(10,3)); // it should return 1000 .
    return(0);
}
