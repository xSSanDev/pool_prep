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
char    *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
int main()
{
    char src[] = "zanass";
    char dest[10];
    ft_putstr("the source is :");
    ft_putstr(src);
    ft_putchar('\n');
    ft_strcpy(dest, src);
    ft_putstr("the Destination is: ");
    ft_putstr(dest);
    ft_putchar('\n');

    return (0);
}