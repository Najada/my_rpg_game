/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	enemy_rect(param_t *g, int anim)
{
	sfIntRect	rect2;

	for (int i = 0 ; g->map[i] ; i++) {
		for (int j = 0 ; g->map[i][j] ; j++) {
			if (g->map[i][j] >= 'a' && g->map[i][j] <= 'f') {
				sfVector2f	t = {j * 60, i * 60};
				rect2 = configure_int_rect(64 * anim,
				64 * 6, 64, 64);
				sfSprite_setTextureRect(g->assets[28].sprite,
				rect2);
				sfSprite_setPosition(g->assets[28].sprite, t);
				sfRenderWindow_drawSprite(g->window,
				g->assets[28].sprite, NULL);
			}
		}
	}
}

void	enemy_anim(param_t *g, param_t *param)
{
	if (sfClock_getElapsedTime(g->player).microseconds > 100000) {
		param->anim->anm2++;
		if (param->anim->anm2 > 5)
			param->anim->anm2 = 0;
		sfClock_restart(g->player);
	}
}

void	attack_rect(param_t *g, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(64 * anim, 64 * 4, 64, 64);
	if (g->p == player1)
		sfSprite_setTextureRect(g->assets[20].sprite, rect2);
	else if (g->p == player2)
		sfSprite_setTextureRect(g->assets[24].sprite, rect2);
	else
		sfSprite_setTextureRect(g->assets[23].sprite, rect2);
}

void	attack_anim(param_t *g)
{
	if (sfClock_getElapsedTime(g->player).microseconds > 100000) {
		g->anim->anm2++;
		if (g->anim->anm2 > 5)
			g->anim->anm2 = 0;
		sfClock_restart(g->player);
	}
}
