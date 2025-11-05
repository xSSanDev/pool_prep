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
int     ft_is_prime(int nb)
{
    if(nb <= 1)
        return 0;
    int     i;
    i = 2;
    while(nb / i >= i)
    {
        if(nb % i == 0 )
            return 0;
        i++;
    }
    return 1;
}
int     ft_find_next_prime(int nb)
{
    if(nb <= 2)
        return 2;
    while(1)
    {
        if(ft_is_prime(nb) == 1)
            return nb;
        nb++;
    }
}
int main()
{
    ft_putnbr(ft_find_next_prime(10));
    return 0;
}
