#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	
	fd = 0;
	fd = open("/Users/lgomes-o/Documents/repos/get_next_line/files/multiple_nlx5", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
//		printf("line: -->%s", line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}	
