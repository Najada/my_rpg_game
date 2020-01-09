/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

int	check_finalbosmove(param_t *g, int y, int x)
{
	if (g->str[y][x] == 'R')
		return (1);
	return (0);
}

void	move_finalbos(param_t *g)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		if (check_finalbosmove(g, g->pos.y + 1, g->pos.x))
			g->pos.y++;
	} else if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		if (check_finalbosmove(g, g->pos.y - 1, g->pos.x))
			g->pos.y--;
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		if (check_finalbosmove(g, g->pos.y, g->pos.x - 1))
			g->pos.x--;
	} else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		if (check_finalbosmove(g, g->pos.y, g->pos.x + 1))
			g->pos.x++;
	}
}

void	draw_final_boss(param_t *p)
{
	for (int i = 0 ; p->str[i] ; i++) {
		p->p_map.y = i * 60;
		for (int j = 0 ; p->str[i][j] ; j++) {
			p->p_map.x = j * 60;
			sfSprite_setPosition(p->assets[18].sprite, p->p_map);
			draw_map_case(p, p->str[i][j]);
		}
	}
}

void	bos_rect(param_t *g, int anim)
{
	sfIntRect rect2 = configure_int_rect(64 * anim,  64 * 17, 64, 64);

	sfSprite_setTextureRect(g->assets[4].sprite, rect2);
}

void	bos_anim(param_t *g, param_t *param)
{
	if (sfClock_getElapsedTime(g->player).microseconds > 100000) {
		param->anim->anm2++;
		if (param->anim->anm2 > 13)
			param->anim->anm2 = 0;
		sfClock_restart(g->player);
	}
}
