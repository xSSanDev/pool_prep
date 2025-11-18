#include <unistd.h>
#include <stdlib.h>

// the seperator checker
int     is_separator(char c, char *charset)
{
        int     i;
        i = 0;
        while(charset[i] != '\0')
        {
                if(charset[i] == c)
                        return (1);
                i++;
        }
        return(0);
}
// the word counter
int     count_words(char *str, char *charset)
{
        int     i;
        int     in_word;
        int     word_count;
        i = 0;
        in_word = 0;
        word_count = 0;
        while(str[i] != '\0')
        {
                if(is_separator(str[i], charset) == 1)
                {
                        in_word = 0; // currently in a separator
                }
                else
                {
                        if(in_word == 0)
                        {
                                word_count++;
                                in_word = 1;
                        }
                }
                i++;
        }
        return (word_count);
}
char    *copy_word(char *str, int start, int end)
{
        int     len;
        char    *new_string;
        int     i;
        len = end - start;
        new_string = (char *)malloc(sizeof(char) * (len + 1));
        if(new_string == NULL)
                return (NULL);
        i = 0;
        while(len > i)
        {
                new_string[i] = str[start + i];
                i++;
        }
        new_string[i] = '\0';
        return(new_string);
}
char    **ft_split(char *str, char *charset)
{
        int     i;
        int     j;
        int     word_count;
        char    **new_array;

        word_count = count_words(str, charset);
        new_array = (char **)malloc(sizeof(char *) * (word_count + 1) );

        if(new_array == NULL)
                return(NULL);
        i = 0;
        j = 0;
        while(str[i] != '\0')
        {
                if(is_separator(str[i], charset) == 1)
                        i++;
                else
                {
                        int start = i;
                        while(str[i] != '\0' && is_separator(str[i], charset) == 0)
                        {
                                i++;
                        }
                        new_array[j] = copy_word(str,start,i);
                        j++;
                }
        }
        new_array[j] = '\0';
        return (new_array);
}
void    ft_putchar(char c)
{
        write(1,&c,1);
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

int main()
{
        //**ft_split(char *str, char *charset)
        char    *string = "Hello,world,this/is/a/test";
        char    *charset = ",/";
        char    **result;
        int     i;
        result = ft_split(string,charset);
        i = 0;
        while(result[i] != 0)
        {
                ft_putstr(result[i]);
                ft_putchar('\n');
                i++;
        }
        i = 0;
        while(result[i] != 0)
        {
                free(result[i]);
                i++;
        }
        free(result);
        return (0);
}
