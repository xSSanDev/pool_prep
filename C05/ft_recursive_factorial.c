#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nb)
{
    long long n_long;
    n_long = nb;

    if(nb >= 10)
        ft_putnbr(n_long / 10);
    ft_putchar((n_long % 10) + '0');
}
int     ft_recursive_factorial(int  nb)
{
    // first case : invalid factorial
    if(nb < 0)
        return 0;
    // base case
    if(nb == 0)
        return 1;
    else
    {
        return (nb * ft_recursive_factorial(nb - 1));
    }
}
int main()
{
    ft_putnbr(ft_recursive_factorial(10));
    return 0;
}
