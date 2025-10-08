#include <unistd.h>
void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putstr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
void    nums(int a, int b)
{
    int current_number = a;
    while(current_number <= b)
    {
        if( current_number >= 1 && current_number <= 9 )
        {
            if(current_number == 1)
            {
                ft_putstr("one");
            }
            else if (current_number == 2)
            {
                ft_putstr("two");
            }
            else if (current_number == 3)
            {
                ft_putstr("three");
            }
            else if (current_number == 4)
            {
                ft_putstr("four");
            }
            else if (current_number == 5)
            {
                ft_putstr("five");
            }
            else if (current_number == 6)
            {
                ft_putstr("six");
            }
            else if (current_number == 7)
            {
                ft_putstr("seven");
            }
            else if (current_number == 8)
            {
                ft_putstr("eight");
            }
            else
            {
                ft_putstr("nine");
            }
        }
        else // number greater than 9
        {
            if(current_number % 2 == 0)
            {
                ft_putstr("even");
            }
            else
            {
                ft_putstr("odd");
            }
        }
        ft_putchar('\n');
        current_number++;
    }
}
int main()
{
    nums(0,20);
    return 0;
}
