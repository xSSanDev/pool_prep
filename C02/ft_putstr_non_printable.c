//--------------------ft_print_non_printable----------------------------//
#include <unistd.h>
void    ft_putchar(char c)
{
        write(1,&c,1);
}
void    ft_putstr_non_printable(char *str)
{
        int i;
        i = 0;
        while(str[i] != '\0')
        {
                if(str[i] >= 32 && str[i] <= 126)
                {
                        ft_putchar(str[i]);
                }
                else
                {
                        char *hex_digits = "0123456789abcdef";
                        unsigned char c = str[i];
                        ft_putchar('\\');
                        ft_putchar(hex_digits[c / 16]);
                        ft_putchar(hex_digits[c % 16]);
                }
                i++;
        }
}
int main()
{
        ft_putstr_non_printable("Hello\nHow are you?");
        return(0);
}