#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_print_alphabet(void)
{
    char character = 'a';
    while(character <= 'z')
    {
        ft_putchar(character);
        character++;
    }
}
int main()
{
    ft_print_alphabet();
    return(0);
}
