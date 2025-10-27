#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nb)
{
    if(nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int    dest_len; // the lenght of dest
    unsigned int    src_len; // the lenght of src
    unsigned int    i; // loop for copiying characters from src
    // fiding the initial lenght of dest
    dest_len = 0;
    while(dest[dest_len] != '\0' && dest_len < size)
    {
        dest_len++;
    }
    // finding the total lenght of src
    src_len = 0;
    while(src[src_len] != '\0')
    {
        src_len++;
    }
    // Handle adge case : dest buffer already too small
    if(dest_len >= size)
    {
        return(size + src_len);
    }
    i = 0;
    while(src[i] != '\0' && (dest_len + i) < (size - 1))
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return(dest_len + src_len);
}
int main()
{
    char s[] = "Hello";
    char d[15] = "Anass";
    unsigned int result;
    result = ft_strlcat(d,s,15);
    ft_putnbr(result);
    ft_putchar('\n');
    return 0;
}