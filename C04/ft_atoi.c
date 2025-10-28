//-------------------------------------ft_atoi.c-----------------------------------------//
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
                nb = -nb;
        }
        if(nb >= 10)
                ft_putnbr(nb / 10);
        ft_putchar((nb % 10) + '0');
}
int     ft_atoi(char *str)
{
        int     i;
        int     sign;// 1 for positive , -1 for negative
        int     result;
        int     digit_value; // for converting char to int (str[i] - '0')
        i = 0;
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        {
                i++;
        }
        sign = 1;
        while(str[i] == '+' || str[i] == '-')
        {
                if(str[i] == '-')
                {
                        sign *= -1;
                }
                i++;
        }
        result = 0;
        while(str[i] >= '0' && str[i] <= '9')
        {
                digit_value = str[i] - '0';
                result = (result * 10) + digit_value;
                i++;
        }
        return (result * sign);
}
int main()
{
        ft_atoi( "---+--+1234ab567");
        ft_putnbr(ft_atoi( "---+--+1234ab567"));
        return 0;
}