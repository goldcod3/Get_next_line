#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	size_t	i;
	int		fd;
	char	*line;
	
	i = 0;
	fd = 0;
	fd = open("/Users/lgomes-o/Documents/repos/get_next_line/dic.txt", O_RDONLY);
	/*
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	*/
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		i++;
	}
	free(line);
	//*/
	return (0);
}	
