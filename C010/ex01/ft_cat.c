#include <unistd.h>
#include <fcntl.h> //for read/write/open
#include <errno.h> // for errno()
#include <string.h> // for strerror()
#include <libgen.h>
void	ft_putstr_error(char *str)
{
	int	i;
	i = 0;
	while(str[i] != '\0')
	{
		write(2,&str[i],1);
		i++;
	}
}
void	display_content(int fd)
{
	int	bytes_read;
	char buffer[28000];

	bytes_read = read(fd,buffer,28000);
	while(bytes_read > 0)
	{
		write(1,buffer,bytes_read);
		bytes_read = read(fd,buffer,28000);
	}
}
int	main(int argc, char *argv[])
{
	int	i;
	int	fd;

	if(argc == 1)
	{
		display_content(0);
		return 0;
	}

	i = 1;
	while(i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if(fd < 0)
		{
			ft_putstr_error("ft_cat: ");
			ft_putstr_error(argv[i]);
			ft_putstr_error(": ");
			ft_putstr_error(strerror(errno));
			ft_putstr_error("\n");
		}
		else
		{
			display_content(fd);
			close(fd);
		}
		i++;
	}
	return(0);
}
