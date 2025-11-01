#include <unistd.h>
#include <stdbool.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nb)
{
    if(nb > 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
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
bool    isValid(char* s)
{
    int i;
    int j;
    i = 0;
    while(s[i] != '\0')
    {
        j = i + 1;
        while(s[j] != '\0')
        {
            if(s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']' || s[i] == '{' && s[j] == '}' )
            {
                return (true);
            }
            j++;
        }
        i++;
    }
    return (false);
}
int main()
{
    char q[] = "[]";
    ft_putnbr(isValid(q));
    return 0;
}


