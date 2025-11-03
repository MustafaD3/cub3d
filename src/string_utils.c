#include "../cub3d.h"
int string_len(char *string)
{
	int i;

	i = 0;
	while(string[i])
		i++;
	return (i);
}
char *string_dup(char *string)
{
	char	*result;
	int		i;

	i = 0;
	while(string[i])
		i++;
	result = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while(string[i])
	{
		result[i] = string[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

int string_find_char(char *string, char chr, int position)
{
	int	i;

	if(position > i)
		i = position;
	else
		i = 0;
	while(string[i])
	{
		if(string[i] == chr)
		{
			printf("Bulundu:%d\n",i);
			return (i);
		}
		i++;
	}
	return (0);
}
