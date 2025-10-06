#include <unistd.h>
void    ft_putchar(char c)
{
  write(1, &c, 1);
}
void    ft_putnbr(int nb)
{
  if(nb < 0)
  {
    ft_putchar('-');
    nb =- nb;
  }
  if(nb >= 10)
  {
    ft_putnbr(nb / 10);
  }
  ft_putchar((nb % 10) + '0');
}
void    ft_ultimate_div_mod(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = temp / *b;
  *b = temp % *b;
}
int main()
{
  int x = 10;
  int y = 3;
  ft_putnbr(x);
  ft_putchar('\t');
  ft_putnbr(y);
  ft_putchar('\n');
  ft_ultimate_div_mod(&x, &y);
  ft_putnbr(x);
  ft_putchar('\t');
  ft_putnbr(y);
  return(0);
}