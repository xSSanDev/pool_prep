#include <unistd.h>
#include <stdlib.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putstr(char *str)
{
    int     i;
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
void    ft_putnbr(int nb)
{
    if(nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}
int     *ft_range(int min, int max)
{
    int     size;
    int     *new_range;
    int     i;

    if(min >= max)
        return (NULL);

    size = max - min;

    new_range = (int *) malloc(sizeof(int) * size);

    if(new_range == NULL)
        return (NULL);

    i = 0;
    while(i < size)
    {
        new_range[i] = min + i;
        i++;
    }
    return (new_range);
}
int main()
{
    int *my_range;
    int i;
    int size;

    size = 11 - 0;
    my_range = ft_range(0, 11);

    if (my_range == NULL)
    {
        ft_putstr("Error: Malloc failed!\n");
    }
    else
    {
        i = 0;
        while (i < size)
        {
            ft_putnbr(my_range[i]);
            ft_putchar('\n');
            i++;
        }
        free(my_range);
    }
    return (0);
}
