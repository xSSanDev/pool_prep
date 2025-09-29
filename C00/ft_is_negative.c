#include <unistd.h>
void    ft_putchar(char k)
{
  write(1, &k, 1);
}
void    ft_is_negative(int n)
{
  if (n >= 0)
  {
    ft_putchar('P');
  }
  else
  {
    ft_putchar('N');
  }
}
int main()
{
  ft_is_negative(44);
  ft_is_negative(-4);
  ft_is_negative(0);
  return (0);
}