#include <unistd.h>
int     ft_strcmp(char *s1, char *s2)
{
    int     i;
    i = 0;
    while(s1[i] != '\0' && s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
int     ft_atoi(char *str)
{
    int     result;
    int     i;
    result = 0;
    i = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

