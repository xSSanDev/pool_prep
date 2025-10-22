#include <unistd.h>
char    *ft_strcat(char *dest, char *src)
{
    // finding the len of dest
    int dest_len;
    dest_len = 0;
    while(dest[dest_len] != '\0')
    {
        dest_len++;
    }
    // copiying characters from src into dest
    int src_index;
    src_index = 0;
    while(src[src_index] != '\0')
    {
        dest[dest_len] = src[src_index];
        dest_len++;
        src_index++;
    }
    dest[dest_len] = '\0';
    return dest;
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
    char dest[20] = "Hello ";
    char src[] = "zanass";

    ft_putstr("Before dest: ");
    ft_putstr(dest);
    ft_putchar('\n');
    ft_putstr("Before src: ");
    ft_putstr(src);
    ft_putchar('\n');

    ft_strcat(dest, src);

    ft_putstr("After dest: ");
    ft_putstr(dest);
    ft_putchar('\n');

    return 0;
}