/*
** EPITECH PROJECT, 2017
** my_malloc
** File description:
** Malloc with exit when fail
*/

# include <stdlib.h>
# include <unistd.h>

void	*my_malloc(unsigned int size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
