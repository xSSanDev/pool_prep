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
int     ft_str_is_printable(char *str)
{
        int i = 0;
        while(str[i] != '\0')
        {
                if(!(str[i] >= 32 && str[i] <= 126))
                {
                        return 0;
                }
                i++;
        }
        return 1;
}
int main()
{
        char a[] = "hello\nWorld";
        int result;
        result = ft_str_is_printable(a);
        ft_putnbr(result);
        return 0;
}