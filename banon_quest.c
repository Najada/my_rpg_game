/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	banon_quest(param_t *p)
{
	static int	k = 0;
	char	*str = BANON;
	char	*tmp;

	if (sfClock_getElapsedTime(p->tc).microseconds > 10000) {
		if (str[k]) {
			k++;
			sfClock_restart(p->tc);
		}
	}
	tmp = my_strndup(str, k);
	display(p, tmp, (sfVector2f){p->pos.x * 30, p->pos.y * 45}, 24);
	free(tmp);
	if (str[k] == '\0') {
		p->quest = alien;
		k = 0;
	}
}

int	check_valid_exit(param_t *param)
{
	if (param->enemy->a < 40)
		return (1);
	if (param->enemy->b < 40)
		return (1);
	if (param->enemy->c < 40)
		return (1);
	if (param->enemy->d < 40)
		return (1);
	if (param->enemy->e < 40)
		return (1);
	if (param->enemy->f < 40)
		return (1);
	return (0);
}

void	end_of_exit(param_t *p, int *k, int index, char *str)
{
	if (str[*k] == '\0') {
		p->quest = alien;
		*k = 0;
		if (index == 0)
			p->map[p->pos.y - 1][p->pos.x] = ' ';
	}
}

void	exit_quest(param_t *p)
{
	char	*str, *tmp;
	static	int	k = 0;
	int	index;

	if ((index = check_valid_exit(p)))
		str = NOT_OK;
	else
		str = OK;
	if (sfClock_getElapsedTime(p->tc).microseconds > 90000) {
		if (str[k]) {
			k++;
			sfClock_restart(p->tc);
		}
	}
	tmp = my_strndup(str, k);
	display(p, tmp, (sfVector2f){p->pos.x * 56, p->pos.y * 45}, 24);
	free(tmp);
	end_of_exit(p, &k, index, str);
}
