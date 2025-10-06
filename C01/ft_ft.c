#include <unistd.h>
void    ft_putchar(char c)
{
        write(1, &c, 1);
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
void    ft_ft(int *nbr)
{
        *nbr = 42;
}
int main()
{
        int my_number;
        my_number = 0;
        ft_putnbr(my_number);
        ft_putchar('\n');
        ft_ft(&my_number);
        ft_putnbr(my_number);
        return(0);
}
