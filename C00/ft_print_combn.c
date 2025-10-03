#include <unistd.h>
void recursive_helper(int n, int combination[], int level, int start_digit);
void    ft_putchar(char c)
{
    write(1, &c ,1);
}
void    ft_print_combn(int n)
{
    int my_array[10];
    recursive_helper(n, my_array, 0, 0);
}
void recursive_helper(int n, int combination[], int level, int start_digit)
{
    if(level == n )
    {
        int i = 0;
        while(i < n)
        {
            ft_putchar(combination[i] + '0');
            i++;
        }
        if (combination[0] != (10 - n))
        {
            ft_putchar(',');
            ft_putchar(' ');
        }
        return;
    }
    int current_digit = start_digit;
    while(current_digit <= 9)
    {
        combination[level] = current_digit;
        recursive_helper(n, combination, level + 1, current_digit + 1);
        current_digit++;
    }
}
int main()
{
    ft_print_combn(3);
    return(0);
}