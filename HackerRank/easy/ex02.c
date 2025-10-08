//-----------------------------------------sum of digits ---------------------------------------//
#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nb)
{
    long n_long = nb;
    if(n_long < 0)
    {
        ft_putchar('-');
        n_long =- n_long;
    }
    if(n_long >= 10)
    {
        ft_putnbr(n_long / 10);
    }
    ft_putchar((n_long % 10) + '0');
}
void    sum_of_digits(int n)
{
    int sum = 0;
    while(n != 0) // while(0) the condition false so the loop not working .
    {
        sum = sum + (n % 10);
        n = n / 10 ;
    }
    ft_putnbr(sum);
    ft_putchar('\n');
}
int main()
{
    sum_of_digits(1434987623);
    return(0);
}