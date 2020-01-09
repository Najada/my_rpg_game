/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

int	main(void)
{
	param_t	*param = NULL;

	param = initiate_params();
	my_rpg(param);
	my_free(param);
	save_score(param);
	return (0);
}
