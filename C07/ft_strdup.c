#include <stdlib.h>
#include <unistd.h>
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
char    *ft_strdup(char *src)
{
    int     i;
    int     len;
    char    *new_string;

    len = 0;
    while(src[len] != '\0')
    {
        len++;
    }
    new_string = (char *)malloc(sizeof(char) * (len + 1));

    if(new_string == NULL)
    {
        return (NULL);
    }
    i = 0;
    while(src[i] != '\0')
    {
        new_string[i] = src[i];
        i++;
    }
    new_string[i] = '\0';
    return(new_string);
}
int main()
{
    char *original = "zanass";
    char *duplicate;
    duplicate = ft_strdup(original);
    if(duplicate == NULL)
    {
        ft_putstr("oops");
        return(1);
    }
    ft_putstr(duplicate);
    ft_putchar('\n');
    free(duplicate);
    return (0);
}