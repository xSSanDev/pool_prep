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
int     ft_sqrt(int nb)
{
    long    i;
    long    nbr_long;

    nbr_long = nb;

    if(nbr_long <= 0)
        return (0);

    i = 1;
    while(i * i <= nbr_long)
    {
        if(i * i == nbr_long)
        {
            return (i);
        }
        i++;
    }
    return (0);
}
int main()
{
    ft_putnbr(ft_sqrt(25));
    return (0);
}