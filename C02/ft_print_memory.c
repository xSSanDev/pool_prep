//*************ft_print_momory.c*******************///
#include <unistd.h>
void	ft_putchar(char c)
{
  write(1, &c, 1);
}
int 	main()
{
  return (0);
}