#include <unistd.h>
void  ft_putchar(char a)
{
  write(1, &a, 1);
}
void    ft_print_reverse_alphabet(void) {
  char character = 'z';
  while (character >='a')
  {
    ft_putchar(character);
    character--;
  }
}
int main()
{
  ft_print_reverse_alphabet();
  return(0);
}