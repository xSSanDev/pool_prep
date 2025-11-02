//-------------------------------ft_iterative_factorial.c----------------------------------------/
#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nbr)
{
    if(nbr >= 10)
    {
        ft_putnbr(nbr / 10);
    }
    ft_putchar((nbr % 10) + '0');
}
int     ft_iterative_factorial(int nb)
{
    long    result;
    int     i;
    if(nb < 0)
        return (0);
    if(nb == 0)
        return (1);
    result = 1;
    i = 0;
    while(nb > i)
    {
        result = result * i;
        i--;
    }
    return (result);
}
int main()
{
    ft_putnbr(ft_iterative_factorial(5));
    return 0;
}
