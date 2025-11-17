#include <unistd.h>
#include <stdlib.h>

// the seperator checker
int     is_seperator(char c, char *charset)
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
        if(is_seperator(str[i], charset) == 1)
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

}
