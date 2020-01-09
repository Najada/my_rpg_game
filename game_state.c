/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include <rpg.h>

void	is_finished(param_t *param)
{
	if (param->stats->life <= 0)
		param->state = gameEnd;
}

void	end(param_t *param)
{
	sfRenderWindow_clear(param->window, sfBlack);
	drawPartBuffer(param);
	display(param, "GAME OVER", (sfVector2f){500, 500}, 200);
	sfRenderWindow_display(param->window);
	sfRenderWindow_setView(param->window, param->view);
}

void	gameend_state(param_t *param)
{
	static int	n = 0;

	if (param->state == gameEnd) {
		if (n == 0) {
			sfView_destroy(param->view);
			sfFloatRect	test;
			test = configure_float_rect(0, 0, 1920, 1080);
			param->view = sfView_createFromRect(test);
		}
		n++;
		end(param);
		if (n > 10) {
			sfSleep(sfMilliseconds(150));
			sfRenderWindow_close(param->window);
		}
	}
}

void	win(param_t *param)
{
	sfRenderWindow_clear(param->window, sfBlack);
	drawPartBuffer(param);
	display(param, "YOU WIN", (sfVector2f){500, 500}, 200);
	display(param, score_to_string(param->stats->life) ,
	(sfVector2f){600, 700}, 200);
	sfRenderWindow_display(param->window);
	sfRenderWindow_setView(param->window, param->view);
}

void	gamewin_state(param_t *param)
{
	static int	n = 0;

	if (param->state == gameWin) {
		if (n == 0) {
			sfView_destroy(param->view);
			sfFloatRect	test;
			test = configure_float_rect(0, 0, 1920, 1080);
			param->view = sfView_createFromRect(test);
		}
		win(param);
		n++;
		if (n > 10) {
			sfSleep(sfMilliseconds(150));
			sfRenderWindow_close(param->window);
		}
	}
}
