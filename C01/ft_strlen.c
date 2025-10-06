#include <unistd.h>
int     ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
int main()
{
    ft_strlen("zanass");
    return(0);
}
