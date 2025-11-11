#include <unistd.h>
#include <stdlib.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nbr)
{
    if(nbr >= 10)
        ft_putnbr(nbr / 10);
    ft_putchar((nbr % 10) + '0');
}
int     ft_ultimate_range(int **range, int min, int max)
{
    int     size;
    int     i;
    if(min >= max)
    {
        *range = NULL;
        return (0);
    }

    size = max - min;

    *range = (int *) malloc(sizeof(int) * size);

    if(*range == NULL )
        return (-1);

    i = 0;
    while(i < size)
    {
        (*range)[i] = min + i;
        i++;
    }
    return(size);
}
int main()
{
    int     *my_array;
    int     array_size;
    int     i;

    array_size = ft_ultimate_range(&my_array,5,12);
    ft_putnbr(array_size);
    ft_putchar('\n');
    i = 0;
    while(i < array_size)
    {
        ft_putnbr(my_array[i]);
        ft_putchar('\t');
        i++;
    }
    free(my_array);
    return (0);

}
