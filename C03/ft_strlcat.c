// *********************initial code cersion ********************//
#include <unistd.h>
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned dest_index;
    unsigned src_index;
    dest_index = 0;
    while(dest[dest_index] != '\0')
    {
        dest_index++;
    }
    src_index = 0;
    while(src[src_index] != '\0')
    {
        dest[dest_index] = src[src_index];
        dest_index++;
        src_index++;
    }
    dest[dest_index] = '\0';

}
