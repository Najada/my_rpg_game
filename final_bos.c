/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	attack_bos(param_t *p, sfVector2f tmp[], int index)
{
	if (sfKeyboard_isKeyPressed(p->keys->space)) {
		if ((int)tmp[index].x == p->pos.x &&
			(int)tmp[index].y == p->pos.y)
			p->enemy->bos++;
		sfSound_play(p->attack);
		attack_rect(p, p->anim->anm2);
		attack_anim(p);
	}
}

void	bos_position(param_t *p)
{
	sfVector2f tmp[] = {{7, 9}, {16, 5}, {16, 10}, {20, 6}, {7, 12}};
	sfTime time  = sfClock_getElapsedTime(p->flower);
	int index  = (int)sfTime_asSeconds(time) / 5;

	if (!((int)sfTime_asSeconds(time) % 5))
		sfSound_play(p->laugh);
	sfSprite_setPosition(p->assets[4].sprite,
	(sfVector2f){tmp[index].x * 60, tmp[index].y * 60});
	sfRenderWindow_drawSprite(p->window,
	p->assets[4].sprite, NULL);
	attack_bos(p, tmp, index);
	if (p->enemy->bos > 200)
		p->state = gameWin;
	if (index >= 5 && p->enemy->bos < 200)
		p->state = gameEnd;
}

void	boss(param_t *p)
{
	sfRenderWindow_clear(p->window, sfBlack);
	draw_final_boss(p);
	draw_player(p);
	player_moving_animation(p);
	bos_rect(p, p->anim->anm2);
	bos_anim(p, p);
	bos_position(p);
	sfRenderWindow_display(p->window);
	sfRenderWindow_setView(p->window, p->view);
}

void	finalbos_state(param_t *p)
{
	static int	n = 0;
	if (p->state == finalBos) {
		if (n == 0) {
			sfView_destroy(p->view);
			sfClock_restart(p->flower);
			sfFloatRect	test;
			test = configure_float_rect(0, 0, 1920, 1080);
			p->view = sfView_createFromRect(test);
			sfRenderWindow_setView(p->window, p->view);
			sfView_zoom(p->view, 0.9);
			sfView_zoom(p->view, 0.9);
			sfView_zoom(p->view, 0.9);
			sfView_zoom(p->view, 0.9);
			p->pos = (sfVector2i) {5, 3};
			n++;
		}
		boss(p);
	}
}
