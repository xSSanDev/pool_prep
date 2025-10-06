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
void    ft_div_mod(int a, int b, int *div, int *mod)
{
        *div = a / b;
        *mod = a % b;
}
int main()
{
        int a = 10;
        int b = 2;
        int div, mod;
        ft_putnbr(a);
        ft_putchar('\t');
        ft_putnbr(b);
        ft_div_mod(a, b, &div, &mod);
        ft_putchar('\n');
        ft_putnbr(div);
        ft_putchar('\t');
        ft_putnbr(mod);
        return(0);
}