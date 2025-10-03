#include <unistd.h>
void ft_putchar(char a)
{
  write(1, &a, 1);
}
int main()
{
  ft_putchar('z');
  ft_putchar('a');
  ft_putchar('n');
  ft_putchar('s');
  ft_putchar('s');
}