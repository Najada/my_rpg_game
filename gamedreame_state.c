/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	dream_quest(param_t *p)
{
	static int	k = 0;
	char	*str = DREAM;
	char	*tmp;

	if (sfClock_getElapsedTime(p->tc).microseconds > 60000) {
		if (str[k]) {
			k++;
			sfClock_restart(p->tc);
		}
	}
	tmp = my_strndup(str, k);
	display(p, tmp, (sfVector2f){300, 50}, 44);
	free(tmp);
	if (str[k] == '\0') {
		p->state = finalBos;
		k = 0;
	}
}

void	draw_skip_button(param_t *p)
{
	if (p->click->skip == 2)
		skip(p, "SKIP", 900, sfBlue);
	else if (p->click->skip == 0)
		skip(p, "SKIP", 900, sfWhite);
	else
		skip(p, "> SKIP", 900, sfWhite);
}

void	gamedream_state(param_t *p)
{
	static int	n = 0;

	if (p->state == gameDream) {
		if (n == 0) {
			sfFloatRect	test;
			test = configure_float_rect(0, 0, 1920, 1080);
			p->view = sfView_createFromRect(test);
		}
		n++;
		sfRenderWindow_clear(p->window , sfBlack);
		sfRenderWindow_drawSprite(p->window,
		p->assets[31].sprite, NULL);
		dream_quest(p);
		draw_skip_button(p);
		sfRenderWindow_display(p->window);
		sfRenderWindow_setView(p->window, p->view);
	}
}
