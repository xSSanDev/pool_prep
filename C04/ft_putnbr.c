#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nb)
{
    long long       n_long;

    n_long = nb;
    if(n_long < 0)
    {
        ft_putchar('-');
        n_long = -n_long;
    }
    if(n_long >= 10)
        ft_putnbr(n_long / 10);
    ft_putchar((n_long % 10) + '0');
}
int main()
{
    ft_putnbr(-2147483648);
    ft_putchar('\n');
    ft_putnbr(5747643);
    return 0;
}
