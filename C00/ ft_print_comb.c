#include <unistd.h>
void    ft_putchar(char d)
{
    write(1, &d, 1);
}
void ft_print_comb(void)
{
    char first_digit; //1
    char second_digit; //2
    char third_digit; //3

    first_digit = '0'; // set first_digit to 0
    while (first_digit <= '9') //the condition is True
    {
        second_digit = '0';  // set second_digit to 0
        while (second_digit <= '9') // the condition is True
        {
            third_digit = '0'; //set the third_digit to 3
            while (third_digit <= '9') // the condition is true
            {
                if (first_digit < second_digit && second_digit < third_digit)// it will skip the if block cause the condition is False
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
                third_digit++; // third_digit will become 1 the 10 the the leave the inner loop
            }
            second_digit++; // first it become 1
        }
        first_digit++;
    }
}
int main() // the compiler start execting the code from the int main
{
    ft_print_comb();
    return (0);
}