#include <unistd.h>
char    *ft_strstr(char *str,char *to_find)
{
    int i;
    int j;

    if(to_find[0] == '\0')
        return (str);
    i = 0;
    while(str[i] != '\0')
    {
        j = 0;
        while(to_find[j] != '\0' && str[i + j] == to_find[j])
        {
            j++;
        }
        if(to_find[j] == '\0')
            return(&str[i]);
        i++;
    }
    return (NULL);
}
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putstr(char *str)
{
    if(str == NULL)
        write(1,"(null)",6);
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
int main()
{
    char haystack[] = "Hello World,";
    char needle[] = "World";
    char *result;
    result = ft_strstr(haystack,needle);
    ft_putstr(result);
    return 0;
}