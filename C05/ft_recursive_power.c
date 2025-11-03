#include <unistd.h>
int     ft_recursive_power(int nb, int power)
{
    if(power < 0)
        return 0;
    if(power == 0)
        return 1;
    if(power > 0)
        return (nb * ft_recursive_power(nb, power - 1));
}
// test : power = 3 ===> 10 * ft_recursive(10, 2)
//        nb = 10 ====>
//        3 * 10 = 30
//        2 * 10 = 20
//        1 * 10 = 10
//        0 * 10 = 0 ===> 1
//        1 * 10 * 20 * 30 = 6000
//
