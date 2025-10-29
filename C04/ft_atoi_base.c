#include <unistd.h>
/*
 * Checks if the given base string is valid for number conversion.
 * A valid base must:
 * 1. Have at least 2 unique characters.
 * 2. Not contain '+' or '-'.
 * 3. Not contain the same character twice.
 * 4. Nor contain these characters ' ', \t, \n, \v, \f, or \r
 * Returns:
 * 1 if the base is valid.
 * 0 if the base is invalid.
 */
int     is_valid_base(char *base)
{
        int     base_len;
        int     i;
        int     j;
        // the base must have more than 2 char
        base_len = 0;
        while(base[base_len] != '\0')
        {
                base_len++;
        }
        if(base_len < 2)
        {
                return (0);
        }
        // the base must not contain '+' or '-' sign
        i = 0;
        while(base[i] != '\0' )
        {
                if(base[i] == '+' || base[i] == '-')
                {
                        return (0);
                }
                i++;
        }
        // not contain the same character twice
        i = 0;
        while(base[i] != '\0')
        {
                j = i + 1;
                while(base[j] != '\0')
                {
                        if(base[i] == base[j])
                        {
                                return (0);
                        }
                        j++;
                }
                i++;
        }
        // not contain these characters ' ', \t, \n, \v, \f, or \r
        i = 0;
        while(base[i] != '\0')
        {
                if(base[i] == ' ' || base[i] == '\t' || base[i] == '\n' || base[i] == '\f' || base[i] == '\r')
                {
                        return (0);
                }
                i++;
        }
        return (1);
}
int     ft_atoi_base(char *str, char *base)
{
        int     len;
        int     i;
        int     sign;
        int     result;
        int     digit_value;

        if(is_valid_base(base) == 0)
        {
                return (0);
        }
        len = 0;
        while(base[len] != '\0')
        {
                len++;
        }
        i = 0;
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        {
                i++;
        }
        sign = 1;
        while(str[i] == '+' || str[i] == '-')
        {
                if(str[i] == '-')
                {
                        sign *= -1;
                }
                i++;
        }
        result = 0;
        while(str[i] >= '0' && str[i] <= '0')
        {
                digit_value = str[i] - '0';
                result = (result * 10) + digit_value;
                i++;
        }
        return (result * sign);

}
