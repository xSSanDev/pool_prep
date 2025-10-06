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
void    ft_swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}
int main()
{
        int a = 10;
        int b = 20;
        ft_putnbr(a);
        ft_putchar('\t');
        ft_putnbr(b);
        ft_putchar('\n');
        ft_swap(&a, &b);
        ft_putnbr(a);
        ft_putchar('\t');
        ft_putnbr(b);
        return(0);
}