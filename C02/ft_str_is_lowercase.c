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
int     ft_str_is_lowercase(char *str)
{
        int i = 0;
        while(str[i] != '\0')
        {
                if(!(str[i] >= 'a' && str[i] <= 'z'))
                {
                        return 0;
                }
                i++;
        }
        return 1;
}
int main()
{
        char a[10] = "fhhdf6";
        int result;
        result = ft_str_is_lowercase(a);
        ft_putnbr(result);
        ft_putchar('\n');
        return 0;
}