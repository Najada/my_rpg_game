/*
** EPITECH PROJECT, 2018
** utils
** File description:
** minishell1
*/

#include <rpg.h>

char	*my_strdup(char *line)
{
	char	*new_line;
	int	i;

	if (line == NULL || line[0] == '\0')
		return (NULL);
	if ((new_line = malloc(sizeof(*new_line) * \
		(my_strlen(line) + 1))) == NULL)
		return (NULL);
	for (i = 0 ; line[i] ; i++)
		new_line[i] = line[i];
	new_line[i] = '\0';
	return (new_line);
}

char	*my_strndup(char *line, int n)
{
	char	*new_line;
	int	i;

	if (line == NULL || line[0] == '\0')
		return (NULL);
	if ((new_line = malloc(sizeof(*new_line) * \
		(my_strlen(line) + 1))) == NULL)
		return (NULL);
	for (i = 0 ; line[i] && i < n ; i++)
		new_line[i] = line[i];
	new_line[i] = '\0';
	return (new_line);
}

int	my_strlen(char const *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

void	my_bzero(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size) {
		buffer[i] = 0;
		i++;
	}
}

int	my_getnbr(char const *str)
{
	int	i;
	int	sgn;
	int	result;

	i = 0;
	sgn = 1;
	result = 0;
	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sgn = -1 * sgn;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i]) {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = sgn * result;
	return (result);
}
