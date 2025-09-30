#include <unistd.h>
void    ft_putchar(char d)
{
    write(1, &d, 1);
}
void ft_print_comb(void)
{
    char first_digit;
    char second_digit;
    char third_digit;

    first_digit = '0';
    while (first_digit <= '9')
    {
        second_digit = '0';
        while (second_digit <= '9')
        {
            third_digit = '0';
            while (third_digit <= '9')
            {
                if (first_digit < second_digit && second_digit < third_digit)
                {
                    ft_putchar(first_digit);
                    ft_putchar(second_digit);
                    ft_putchar(third_digit);
                    if (first_digit != '7' || second_digit != '8' || third_digit != '9')
                    {
                        ft_putchar(',');
                        ft_putchar(' ');
                    }
                }
                third_digit++;
            }
            second_digit++;
        }
        first_digit++;
    }
}
int main()
{
    ft_print_comb();
    return (0);
}