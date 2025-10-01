#include <unistd.h>
void    ft_putchar(char d)
{
    write(1, &d ,1);
}
void    ft_print_comb2(void)
{
    int i ;
    int j ;
    i = 0;
    while(i <= 98)
    {
        j = i + 1;
        while(j <= 99)
        {
            ft_putchar((i / 10) + '0');
            ft_putchar((i % 10) + '0');
            ft_putchar(' ');
            ft_putchar((j / 10) + '0');
            ft_putchar((j % 10) + '0');
            //ft_putchar(',');
            if(i != 98 || j != 99)
            {
                ft_putchar(',');
                ft_putchar(' ');
            }
            j++;
        }
        i++;
    }
}
int main()
{
    ft_print_comb2();
    return(0);
}
