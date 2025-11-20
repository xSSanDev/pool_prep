#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H
#include <unistd.h>
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define EVEN_MSG "I have an even number of arguments"
#define ODD_MSG "I have an odd number of arguments"
typedef int t_bool;
# define EVEN(nbr) (nbr % 2 == 0)
#endif

