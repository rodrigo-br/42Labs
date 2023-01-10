#include "map_symbols.h"

/**
 * @brief constroy_map Auxiliar function, called in case of error in malloc
 * free map and set to NULL
 * 
 * @param map t_map
 * @param position	the index position to malloc that failed
 */
static void error_malloc_map(t_map map, int position)
{
	int index = 0;

	while (index < position)
	{
		free(map[index]);
		index++;
	}
	free(map);
	map = NULL;
}

t_map constroy_map(int height)
{
	t_map map = (t_map)malloc(sizeof(char *) * 256);
	if (!map)
		return (NULL);
	for (int i = 0; i < 256; i++) {
		map[i] = (char *)calloc((height + 1), sizeof(char));
		if (!map[i])
			return (error_malloc_map(map, i), NULL);
	}
	map[255] = NULL;
	return (map);
}