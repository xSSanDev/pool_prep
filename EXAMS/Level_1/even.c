/*Assignment name  : even
Expected files   : even.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program That displays  even numbers, followed by a new line.

Example:

$> ./even
0246810
$> ./even | cat -e
0246810$
==========================================================================================
*/
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
void    print_even_numbers(void)
{
    int i = 0;
    while(i <= 10)
    {
        if(i % 2 == 0)
            ft_putnbr(i);
        ft_putchar('\t');
        i++;
    }
}
int main()
{
    print_even_numbers();
    return 0;
}