#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int     *ft_strcmp(char *s1, char *s2)
{
        int     c;
        c = 0;
        while(s1[c] != '\0' && s1[c] == s2[c])
        {
                c++;
        }
        return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
int     ft_atoi(char *str)
{
        int     i = 0;
        int     sign = 1;
        int     result = 0;
        //Skip whitespace
        while(str[i] == ' ' || str[i] == >= 9 && str[i] <= 13)
                i++;
        //handle signs
        if(str[i] == '+')
                i++;
        else if(str[i] == '-')
        {
                sign = -1;
                i++;
        }
        // convert numbers
        while(str[i] >= '0' && str[i] <= '9')
        {
                result = result * 10 + (str[i] - '0');
                i++;
        }
        return (result * sign);
}
void    ft_putchar(char c)
{
        write(1,&c,1);
}
int     ft_putnbr(int nb)
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
int main(int argc, char *argv[])
{
        int     i;
        int     num_bytes;

        num_bytes = 0;
        i = 1;
        while(i < argc - 1)
        {
                if(ft_strcmp(argv[i], "-c") == 0)
                {
                        num_bytes = ft_atoi(argv[i + 1]);
                        break;
                }
                i++;
        }
        if(num_bytes > 0)
        {
                write(1,"Scuuess! found size.\n",21);
        }
        else
        {
                write(1,"No valid size found.\n",21);
        }
        return (0);

}
