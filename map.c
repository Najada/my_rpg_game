/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

file	*open_file(char const *filepath)
{
	file	*stream;

	stream = fopen(filepath, "r");
	if (stream == NULL)
		write(1, "Could not open file\n", 20);
	return (stream);
}

char	**get_map(char *str)
{
	int	height = 0;
	int	i = 0;
	char	**map = NULL;
	file	*stream;
	size_t	len;
	ssize_t	read;
	char	*line = NULL;

	stream = open_file(str);
	getline(&line, &len, stream);
	height = my_getnbr(line);
	getline(&line, &len, stream);
	map = malloc(sizeof(*map) * (height + 1));
	while ((read = getline(&line, &len, stream)) != -1)
		map[i++] = my_strdup(line);
	map[i] = NULL;
	free(line);
	fclose(stream);
	return (map);
}

char	**get_key(char *str)
{
	int	height = 0;
	int	i = 0;
	char	**map = NULL;
	file	*stream;
	size_t	len;
	ssize_t	read;
	char	*line = NULL;

	stream = open_file(str);
	getline(&line, &len, stream);
	height = my_getnbr(line);
	getline(&line, &len, stream);
	map = malloc(sizeof(*map) * (height + 1));
	while ((read = getline(&line, &len, stream)) != -1)
		map[i++] = my_strdup(line);
	map[i] = NULL;
	free(line);
	fclose(stream);
	return (map);
}
