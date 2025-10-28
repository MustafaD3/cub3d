#include "cub3d.h"
int main(int argc,char **argv)
{
	char	*map;
	if(argc != 2)
		return (1);
	if(!extension_control(argv[1]))
		return (1);
	map = open_and_read_map(argv[1]);
	return (0);
}