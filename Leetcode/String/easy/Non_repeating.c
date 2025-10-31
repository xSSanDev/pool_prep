/*Question 1:Non repeating character - You are given a string consisting of only lower case and upper-case English
Alphabets and integers 0 to 9. Write a function that will take this string as Input and return the index of the first
character that is non-repeating.*/
#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putnbr(int nb)
{
    if(nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if(nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}
int     non_repeating_char(char *str)
{
    int     i;
    int     j;
    int     is_duplicate;

    i = 0;
    while(str[i] != '\0')
    {
        is_duplicate = 0; // assume the char is unique
        j = 0;

        while(str[j] != '\0')
        {
            if(i != j && str[i] == str[j])
            {
                is_duplicate = 1;
                break;
            }
            j++;
        }
        if(is_duplicate == 0)
        {
            return(i);
        }
        i++;
    }
    return (-1);
}
int main()
{
    ft_putnbr(non_repeating_char("aaBccBAA"));
    return 0;
}
