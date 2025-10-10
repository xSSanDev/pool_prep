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
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar((nb % 10) + '0');
}
int ft_str_is_alpha(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            return (0);
        }
        i++;
    }
    return (1);
}
int main()
{
    char a[10] = "Anass";
    char b [10] = "hel34lo";
    int result;
    int result_2;
    result = ft_str_is_alpha(a);
    ft_putnbr(result);
    ft_putchar('\n');
    result_2 = ft_str_is_alpha(b);
    ft_putnbr(result_2);
    return(0);
}