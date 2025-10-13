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
        nb =- nb;
    }
    if(nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar((nb % 10) + '0');
}
int     get_value(char c)
{
    if(c == 'I')
    {
        return 1;
    }
    else if(c == 'V')
    {
        return 5;
    }
    else if(c == 'X')
    {
        return 10;
    }
    else if(c == 'L')
    {
        return 50;
    }
    else if(c == 'C')
    {
        return 100;
    }
    else if(c == 'D')
    {
        return 500;
    }
    else if(c == 'M')
    {
        return 1000;
    }

    return 0;
}
int romanToInt(char* s)
{
    int i = 0;
    int total = 0;

    while (s[i] != '\0')
    {
        // Get the value of the current character.
        int current_value = get_value(s[i]);

        // Check if there is a next character to compare with.
        if (s[i + 1] != '\0')
        {
            int next_value = get_value(s[i + 1]);

            if (current_value < next_value)
            {
                // Subtraction case (e.g., "IV" -> 5 - 1)
                total = total + (next_value - current_value);
                i += 2; // Move past BOTH characters we just processed.
            }
            else
            {

                total = total + current_value;
                i++;
            }
        }
        else
        {
            total = total + current_value;
            i++;
        }
    }
    return total;
}
int main()
{
    char q[] = "XIX";
    int result = romanToInt(q);
    ft_putnbr(result);
    return(0);
}