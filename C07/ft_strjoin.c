#include <unistd.h>
#include <stdlib.h>
/* =====================================exemple =============================================
 * size = 3
 * strs = {"Hello","World", "!"}
 * sep = ", "
 * result : "Hello, World, !"
 * */
void    ft_putchar(char c)
{
        write(1,&c,1);
}
int     ft_strlen(char *str)
{
        int     i;
        i = 0;
        while(str[i] != '\0')
                i++;
        return(i);
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
        char    *new_string;
        int     total_len;
        int     i;
        int     j;
        int     k;
//-----------------the size == 0 case-------------------//
        if(size == 0)
        {
                new_string = (char *)malloc(sizeof(char) * 1);
                if(new_string == NULL)
                        return (NULL);
                new_string[0] = '\0';
                return(new_string);
        }
//-----------------calculate total lenght---------------//
        total_len = 0;
        i = 0;
        while(i < size)
        {
                total_len += ft_strlen(strs[i]);
                i++;
        }
        total_len += (ft_strlen(sep) * (size - 1));
        total_len += 1; // for '\0'
//------------------Allocate Memory-------------------------//
        new_string = (char *)malloc(sizeof(char) * total_len);
        if(new_string == NULL)
                return (NULL);
//-----------------Copy strings and separators------------//
        i = 0; // loop through the array of string
        k = 0; // tracks our position in new_string
        while(i < size)
        {
                j = 0; //loop through the characters of strs[i]
                while(strs[i][j] != '\0')
                {
                        new_string[k] = strs[i][j];
                        j++;
                        k++;
                }
                if(i < size - 1)
                {
                        j = 0;
                        while(sep[j] != '\0')
                        {
                                new_string[k] = sep[j];
                                j++;
                                k++;
                        }
                }
                i++;
        }
        new_string[k] = '\0';
        return (new_string);
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
int main(void)
{
        char *words[] = {"Hello", "world", "from", "Anass"};
    char *sep = "/";
    int size = 4;

    char *result = ft_strjoin(size, words, sep);
    ft_putstr("Joined string: ");
    ft_putstr(result);
    ft_putchar('\n');
    free(result);
    return (0);
}