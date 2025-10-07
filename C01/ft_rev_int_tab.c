#include <unistd.h>
void    ft_putchar(char c)
{
        write(1,&c,1);
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
void    ft_swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}
void    ft_rev_int_tab(int *tab, int size)
{
        int start = 0;
        int end = size - 1;
        while(start < end)
        {
                ft_swap(&tab[start], &tab[end]);
                start++;
                end--;
        }
}
int main()
{
        int my_array[5] = {12, 21, 5, 54, 4};
        ft_putstr("the array element before reverse is :");
        ft_putchar('\n');
        int i = 0;
        while(i < 5)
        {
                ft_putnbr(my_array[i]);
                ft_putchar('\t');
                i++;
        }
        ft_putchar('\n');
        ft_putstr("the array elements after reverse is :");
        ft_putchar('\n');
        ft_rev_int_tab(my_array , 5);
        i = 0;
        while(i < 5)
        {
                ft_putnbr(my_array[i]);
                ft_putchar('\t');
                i++;
        }
        return(0);
}