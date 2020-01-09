/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	title_anim(param_t *g, param_t *param)
{
	if (sfClock_getElapsedTime(g->player).microseconds > 100000) {
		param->anim->anm2++;
		if (param->anim->anm2 > 8)
			param->anim->anm2 = 1;
		sfClock_restart(g->player);
	}
}

void	control_flower(param_t *g)
{
	sfTime time  = sfClock_getElapsedTime(g->flower);

	if (sfTime_asSeconds(time) > 5.0 && g->fflower)
		g->fflower = 0;
}

void	check_flower(param_t *param)
{
	if (param->map[param->pos.y][param->pos.x] == 'L') {
		param->map[param->pos.y][param->pos.x] = ' ';
		param->fflower = 1;
		sfClock_restart(param->flower);
	} else if (param->map[param->pos.y][param->pos.x] == 'M') {
		param->map[param->pos.y][param->pos.x] = ' ';
		param->stats->life = param->stats->life - 25;
		sfSound_play(param->hurt);
	}
}
