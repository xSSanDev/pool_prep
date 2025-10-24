/*Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>*/
#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putstr(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
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
void    fizzbuzz(void)
{
    int i;
    i = 1;
    while(i <= 100)
    {
        if(i % 5 == 0 && i % 3 == 0)
        {
            ft_putstr("fizzbuzz");
            ft_putchar('\n');
        }
        else if(i % 3 == 0)
        {
            ft_putstr("fizz");
            ft_putchar('\n');
        }
        else if(i % 5 == 0)
        {
            ft_putstr("buzz");
            ft_putchar('\n');
        }
        else
        {
            ft_putnbr(i);
            ft_putchar('\n');
        }

        i++;
    }

}
int main()
{
    fizzbuzz();
    return 0;
}