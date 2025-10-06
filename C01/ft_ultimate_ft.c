#include <unistd.h>
void    ft_putchar(char c)
{
        write(1, &c, 1);
}
void    ft_ultimate_ft(int *********nbr)
{
        *********nbr = 42;
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
int main()
{
        int my_number ;
        int *ptr1 = &my_number;
        int **ptr2 = &ptr1;
        int ***ptr3 = &ptr2;
        int ****ptr4 = &ptr3;
        int *****ptr5 = &ptr4;
        int ******ptr6 = &ptr5;
        int *******ptr7 = &ptr6;
        int ********ptr8 = &ptr7;
        int *********ptr9 = &ptr8;
        my_number = 787;
        ft_putnbr(my_number);
        ft_putchar('\n');
        ft_ultimate_ft(ptr9);
        ft_putnbr(my_number);
        return(0);
}