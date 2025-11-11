#include <unistd.h>
#include <stdlib.h>

/* ========================exemple =============================================
 * size = 3
 * strs = {"Hello","World", "!"}
 * sep = ", "
 * result : "Hello, World, !"
 * */
int     strlen(char *str)
{
    int     i;
    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}
char    *ft_strjoin(int size,char **strs, char *sep)
{
    char    *new_string;
    int     total_len;
    int     i;

    if(size == 0)
    {
        new_string = (char *)malloc(sizeof(char) * 1);
        if(new_string == NULL)
            return(NULL);
        new_string[0] = '\0';
    }
    total_len = 0;
    i = 0;
    while(i < size)
    {
        total_len = total_len + ft_strlen(strs[i]);
        i++;
    }
    total_len = total_len + 1;

}
