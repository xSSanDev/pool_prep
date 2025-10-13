//--------------------------------------------------------------------------------------------------------------------//
/*Given an array of integers and a specific target number, the goal is to find the two numbers withinthe array that add
up to the target.The solution should be an array containing the indices (positions) of these two numbers. It's guaranteed
that there is always exactly one correct pair in the array, and the same element cannot be used twice.*/
//--------------------------------------------------------------------------------------------------------------------//
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
        nb =- nb;
    }
    if(nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar((nb % 10) + '0');
}
void    find_And_print_Two_sum(int *num, int numSize,int target)
{
    int i;
    int j;
    i = 0;
    while(i < numSize)
    {
        j = i + 1;
        while(j < numSize)
        {
            if(num[i] + num[j] == target)
            {
                ft_putchar('[');
                ft_putnbr(i);
                ft_putchar(',');
                ft_putnbr(j);
                ft_putchar(']');

                return;
            }
            j++;
        }
        i++;
    }
}
int main()
{
    int a[] = {2,5,7,3,10};
    find_And_print_Two_sum(a, 5, 9);
    return 0;
}