#include<unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
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
    ft_putchar((nb % 10 )+ '0');
}
void update(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *a + *b;
    *b = temp - *b;
}
int main() {
    int a = 10;
    int b = 10;
    update(&a, &b);
    ft_putnbr(a);
    ft_putchar('\n');
    ft_putnbr(b);
    return 0;
}
