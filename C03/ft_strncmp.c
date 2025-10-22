#include <unistd.h>
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
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');

}
int     ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    if(n == 0)
        return 0;

    i = 0;
    while(s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
    {
        i++;
    }
    return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
int main()
{
    char a[10] = "Hello";
    char b[10] = "helLo";
    ft_strncmp(a,b,4);
    ft_putnbr(ft_strncmp(a,b,4));
    return 0;
}