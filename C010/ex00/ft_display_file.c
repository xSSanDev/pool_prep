void    ft_putchar(char c)
{
    write(2,&c,1);
}
int     main(int argc, char *argv[])
{
    if(argc == 1)
    {
        ft_putchar('F');
        ft_putchar('i');
        ft_putchar('l');
        ft_putchar('e');
        ft_putchar(' ');
        ft_putchar('n');
        ft_putchar('a');
        ft_putchar('m');
        ft_putchar('e');
        ft_putchar(' ');
        ft_putchar('i');
        ft_putchar('s');
        ft_putchar(' ');
        ft_putchar('m');
        ft_putchar('e');
        ft_putchar('s');
        ft_putchar('s');
        ft_putchar('i');
        ft_putchar('n');
        ft_putchar('g');
    }
    if(argc > 2)
    {
        ft_putchar('t');
        ft_putchar('o');
        ft_putchar(' ');
        ft_putchar('m');
        ft_putchar('a');
        ft_putchar('n');
        ft_putchar('y');
        ft_putchar(' ');
        ft_putchar('a');
        ft_putchar('r');
        ft_putchar('g');
        ft_putchar('u');
        ft_putchar('m');
        ft_putchar('e');
        ft_putchar('n');
        ft_putchar('t');
    }
}
