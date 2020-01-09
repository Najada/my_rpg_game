/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	fire_anim(param_t *g)
{

	if (sfClock_getElapsedTime(g->f).microseconds > 100000) {
		g->anim->number++;
		if (g->anim->number > 8) {
			g->anim->number = 1;
			g->fire = 0;
		} else
			sfClock_restart(g->f);
	}
}

void	is_player_hurt(param_t *g, int i, int j)
{
	if (g->pos.x == i && g->pos.y == j + 1) {
		g->stats->life -= 5;
		sfSound_play(g->hurt);
	}
}

void	draw_fire(param_t *g, int anim)
{
	sfIntRect	rect2;

	for (int i = 0 ; g->map[i] ; i++) {
		for (int j = 0 ; g->map[i][j] ; j++) {
			if (g->map[i][j] >= 'a' && g->map[i][j] <=  'f') {
				sfVector2f t = {j * 60, i * 60};
				is_player_hurt(g, j, i);
				rect2 = configure_int_rect(100 * anim,
				0, 100, 100);
				sfSprite_setTextureRect(g->assets[29].sprite,
				rect2);
				sfSprite_setPosition(g->assets[29].sprite, t);
				sfRenderWindow_drawSprite(g->window,
				g->assets[29].sprite, NULL);
			}
		}
	}
}
