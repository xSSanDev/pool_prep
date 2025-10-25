/*Write a function that takes a list of strings and finds the longest sequence of characters that is exactly the same at
 *the beginning of all the strings. [cite: leetcode_prefix.png] For instance, with "flower", "flow", and "flight",
 *the common prefix is "fl". If there's no common starting part, like with "dog", "racecar", and "car", the prefix is
 *empty. Your function should print this common prefix character by character.*/
//*********************************************************************************************************************//
#include <unistd.h>
void    ft_putchar(char c)
{
    write(1,&c,1);
}
void    ft_putstr(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
void    longestCommonPrefix(char** strs, int strsSize)
{
    int i; // index for characters within strings
    int j; // index for iterating rhrough the different strings

    // Empty list : case 1
    if(strsSize == 0)
    {
        ft_putchar('\n');
        return;
    }

    // only one string i the list
    if(strsSize == 1)
    {
        ft_putstr(strs[0]);
        ft_putchar('\n');
        return;
    }
    i = 0;
    // outer loop : Iterate through characters of the first string
    while(strs[0][i] != '\0')
    {
        char current_char = strs[0][i];
        j = 1;
        while(j < strsSize)
        {
            if(strs[j][i] == '\0' || strs[j][i] != current_char)
            {
                // 1.if the current string strs[j] ends early or
                // 2.if the current string strs[j][i] doesn't match current_char
                ft_putchar('\n');
                return;
            }
            j++; //move to the next string
        }
        ft_putchar(current_char);
        i++;
    }
    ft_putchar('\n');

}
int main()
{
    char *list[] = {"flower","flow","flight"};
    longestCommonPrefix(list,3);
    return 0;
}

