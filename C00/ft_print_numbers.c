#include<unistd.h>
void    ft_putchar(char q)
{
    write(1,&q,1);
}
void    ft_print_numbers(void)
{
    char digit = '0';
    while(digit <= '9')
    {
        ft_putchar(digit);
        digit++;
    }
}
int main()
{
    ft_print_numbers();
    return(0);
}
