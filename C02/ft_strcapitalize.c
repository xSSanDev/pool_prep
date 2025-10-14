#include <unistd.h>
void    ft_putchar(char c)
{
  write(1, &c, 1);
}
void    ft_putstr(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    ft_putchar(str[i]);
    i++;
  }
}
char    *ft_strcapitalize(char *str)
{
    int i;
    int is_start_of_word;

    i = 0;
    is_start_of_word = 1;

    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            if(is_start_of_word == 1)
            {
                str[i] = str[i] - 32;
            }
        }
        else if(str[i] >= 'A' && str[i] <= 'Z' )
        {
            if(is_start_of_word ==  0)
            {
                str[i] = str[i] + 32;
            }
        }
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
        {
            is_start_of_word = 0;
        }
        else
        {
            is_start_of_word = 1;
        }
        i++;
    }
    return str;
}
int main()
{
  char q[] = "hello 2am ZanAss";
  ft_strcapitalize(q);
  ft_putstr(q);
  ft_putchar('\n');
  return 0;
}
