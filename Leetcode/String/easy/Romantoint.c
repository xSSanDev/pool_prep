/*This problem requires you to convert a string of Roman numerals into its corresponding integer. The process involves              //
 *summing the values of the symbols, which are typically written largest to smallest from left to right (e.g., VII = 5 + 1 + 1 = 7).//
 *The main challenge is the subtraction rule, where a smaller numeral placed before a larger one signifies subtraction,             //
 *such as IV for 4 (5 - 1) and IX for 9 (10 - 1). Your function must correctly interpret these special cases to calculate           //
 *the final integer value.*/                                                                                                        //
//----------------------------------------------------------------------------------------------------------------------------------//
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
        int current_value = get_value(s[i]);
        if (s[i + 1] != '\0')
        {
            int next_value = get_value(s[i + 1]);
            if (current_value < next_value)
            {
                total = total + (next_value - current_value);
                i += 2;
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