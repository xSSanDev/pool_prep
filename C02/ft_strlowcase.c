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
char    *ft_strlowcase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
         if (str[i] >= 'A' && str[i] <= 'Z')
          {
              str[i] = str[i] + 32;
          }
          i++;
    }
    return str;
}
int main()
{
  char q[] = "ZANASS";
  ft_strlowcase(q);
  ft_putstr(q);
  ft_putstr("\n");
  return 0;
}
