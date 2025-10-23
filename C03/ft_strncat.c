#include <unistd.h>
char    *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int dest_index;
    unsigned int src_index;

    dest_index = 0;
    while(dest[dest_index] != '\0')
    {
        dest_index++;
    }

    src_index = 0;
    while(src[src_index] != '\0' &&  src_index < nb)
    {
        dest[dest_index] = src[src_index];
        dest_index++;
        src_index++;
    }
    dest[dest_index] = '\0';
    return (dest);
}
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
int main()
{
    char a[20] = "Hello ";
    char b[] = "Anass";
    ft_strncat(a,b,7);
    ft_putstr(a);
    ft_putchar('\n');
    return 0;
}