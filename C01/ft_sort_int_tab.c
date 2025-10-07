#include <unistd.h>
void    ft_putchar(char c)
{
        write(1,&c,1);
}
void    ft_swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}
void    ft_sort_int_tab(int *tab, int size)
{
        int i;
        int j;
        i = 0;
        while(i < size - 1)
        {
                j = 0;
                while(j < size - 1 - i)
                {
                        if(tab[j] > tab[j + 1])
                        {
                                ft_swap(&tab[j], &tab[j+1]);
                        }
                        j++;
                }
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
void    ft_putstr(char *str)
{
        int i = 0;
        while(str[i] != '\0')
        {
                ft_putchar(str[i]);
                i++;
        }
}
int main()
{
        int my_array[5] = {2, 3, 4, 5,3};
        int i = 0;
        ft_putstr("the array elements is :");
        ft_putchar('\n');
        while(i < 5)
        {
                ft_putnbr(my_array[i]);
                ft_putchar('\t');
                i++;
        }
        ft_putchar('\n');
        ft_putstr("the array after be sorted is :");
        ft_putchar('\n');
        ft_sort_int_tab(my_array, 5);
        i = 0;
        while(i < 5)
        {
                ft_putnbr(my_array[i]);
                ft_putchar('\t');
                i++;
        }
        return(0);
}