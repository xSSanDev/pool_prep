#ifndef FT_STRS_TO_TAB_H
# define FT_STRS_TO_TAB_H
#include <stdlib.h>
typedef struct s_stock_str
{
  int size;
  char *str;
  char *copy;
}t_stock_str;
int  ft_strlen(char *str)
{
  int i;
  i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return (i);
}
char    *ft_strdup(char *src)
{
  int     i;
  int     len;
  char    *new_string;

  len = 0;
  while(src[len] != '\0')
  {
    len++;
  }
  new_string = (char *)malloc(sizeof(char) * (len + 1));

  if(new_string == NULL)
  {
    return (NULL);
  }
  i = 0;
  while(src[i] != '\0')
  {
    new_string[i] = src[i];
    i++;
  }
  new_string[i] = '\0';
  return(new_string);
}
struct  s_stock_str *ft_strs_to_tab(int ac, char **av)
{
  int     i;
  t_stock_str *array;
  array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
  if(array == NULL)
    return (NULL);
   i = 0;
   while(i < ac)
   {
     array[i].size = ft_strlen(av[i]);
     array[i].str = av[i];
     array[i].copy = ft_strdup(av[i]);
     i++;
   }
   array[i].str = 0;
   return (array);
}
#endif