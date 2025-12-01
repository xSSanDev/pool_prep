#include <unistd.h>
#include <fcntl.h> // required for open()
void    ft_putchar(char c)
{
	write(1,&c,1);
}
void    ft_putstr_err(char *str)
{
	int     i;
	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_display_file(char *filename)
{
	int	fd; //file descriptor
	int	ret; // return value of read (how many bytes read)
	int	buffer[1024]; //our "bucket" to hold data

	//1. Open file in Read-Only mode
	fd = open(filename, O_RDONLY);
	if(fd == -1)
	{
		ft_putstr_err("Cannot read the file. \n");
		return;
	}
	ret = read(fd, buffer, 1024);
	while(ret > 0)
	{
		write(1,buffer,ret);
		ret = read(fd, buffer, 1024);
	}
	close(fd);
}
int	main(int argc, char *argv[])
{
	if(argc == 1)
	{
		ft_putstr_err("File name missing. \n");
		return(0);
	}
	if(argc > 2)
	{
		ft_putstr_err("To many arguments. \n");
		return(0);
	}
	ft_display_file(argv[1]);
	return(0);
}
