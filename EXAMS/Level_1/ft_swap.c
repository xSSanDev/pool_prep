/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/
#include <unistd.h>
void    ft_putchar(char c)
{
  write(1,&c,1);
}
void    ft_putnbr(int nb)
{
  if(nb < 0)
  {
    ft_putchar('-');
    nb = -nb;
  }
  if(nb >= 10)
    ft_putnbr(nb / 10);
  ft_putchar((nb % 10) + '0');
}
void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
int main()
{
  int a = 10;
  int b = 20;
  swap(&a, &b);
  ft_putnbr(a);
  ft_putchar('\n');
  ft_putnbr(b);
  return 0;
}