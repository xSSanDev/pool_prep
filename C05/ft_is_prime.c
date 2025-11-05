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
int     ft_is_prime(int nb)
{
        // a prime numbre is greater than 1 and only divesor are 1 and itself
        // return 1 if number is prime
        // return 0 if not .
        int     i;
        if(nb <=1 )
                return 0;

        i = 2;
        while(nb / i >= i)
        {
                if(nb % i == 0)
                        return 0;
                i++;
        }
        return 1;
}
int main()
{
        ft_putnbr(ft_is_prime(13));
        return 0;
}
