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
char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i = 0;
    while(src[i] != '\0' && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while(i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
int main()
{
    char src[] = "zanass";
    char dest[8];
    int n = 10;
    ft_putstr(src);
    ft_putchar('\n');
    ft_strncpy(dest, src, n);
    ft_putstr(dest);
    return(0);
}