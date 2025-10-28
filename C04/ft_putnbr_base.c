#include <unistd.h>
int     is_base_valid(char *base)
{
    // Must not be empty or have one character ,at least 2
    // must not contain + or -
    // must not contain the same character twice
    // if all checks faills : return 0 otherwise return 1;
    int     len;
    int     i;
    int     j; // Added for the duplicate check loop
    // Check 1: Length
    len = 0;
    while (base[len] != '\0')
        len++;
    if (len < 2)
        return (0);
    // Check 2: No '+' or '-'
    i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == '+' || base[i] == '-')
        {
            return (0);
        }
        i++;
    }
    // Check 3: No Duplicates
    i = 0;
    while (base[i] != '\0')
    {
        j = i + 1; // Start inner loop from the next character
        while (base[j] != '\0')
        {
            if (base[i] == base[j]) // Found a duplicate
                return (0);
            j++;
        }
        i++;
    }

    // If all checks passed
    return (1);
}
void    ft_putnbr_base(int nb,char *base)
{

}