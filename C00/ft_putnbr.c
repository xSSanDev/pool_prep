#include <unistd.h>
void    ft_putchar(char r)
{
     write(1, &r, 1);
}
void     ft_putnbr(long int nb)
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
  ft_putchar((nb % 10 ) + '0' );
}
int main()
{
  ft_putnbr(104334345);
  ft_putchar('\n');
  ft_putnbr(0);
  ft_putchar('\n');
  ft_putnbr(-78434334);
  return 0;
}