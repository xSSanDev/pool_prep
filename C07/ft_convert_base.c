#include <unistd.h>
#include <stdlib.h>
//----------exemple--------------------------------//
/*nbr = "101010"
 * base_from = "01
 * base_to = "0123456789ABCDEF"
 * result = "2A"
 */
int     is_valid_base(char *base)
{
        int     base_len;
        int     i;
        int     j;
// the base should have more than two chars
        base_len = 0;
        while(base[base_len] != '\0')
                base_len++;
        if(base_len < 2)
                return (0);
// the base must not contain '+' or '-' sign
        i = 0;
        while(base[i] != '\0')
        {
                if(base[i] == '+' || base[i] == '-')
                        return (0);
                i++;
        }
// not contain the same characters twise
        i = 0;
        while(base[i] != '\0')
        {
                j = i + 1;
                while(base[j] != '\0')
                {
                        if(base[i] == base[j])
                                return (0);
                        j++;
                }
                i++;
        }
// not contains these characters
        i = 0;
        while(base[i] != '\0')
        {
                if(base[i] == ' '|| base[i] == '\t' || base[i] == '\n' || base[i] == '\f' || base[i] == '\r' || base[i] == '\v')
                        return (0);
                i++;
        }
        return (1);
}
int     get_char_index(char c,char *base)
{
        int     i;
        i = 0;
        while(base[i] != '\0')
        {
                if(base[i] == c)
                        return (i);
                i++;
        }
        return (-1);
}
char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
        int     len;
        int     i;
        int     sign;
        int     result;
        int     digit_value;

        if(is_valid_base(base_from) == 0)
                return(NULL);
        if(is_valid_base(base_to) == 0)
                return(NULL);
        len = 0;
        while(base_from[len] != '\0')
                len++;

        i = 0;
        while(nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == '\v' || nbr[i] == '\f' || nbr[i] == '\r')
                i++;

        sign = 1;
        while(nbr[i] == '+' || nbr[i] == '-')
        {
                if(nbr[i] == '-')
                        sign *= -1;
                i++;
        }
        result = 0;
        digit_value = get_char_index(nbr[i],base_from);
        while(digit_value != -1)
        {
                result = (result * len) + digit_value;
                i++;
                digit_value = get_char_index(str[i], base_from);
        }
        return (result * sign);
}
