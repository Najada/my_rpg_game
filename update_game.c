/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	draw_player(param_t *p)
{
	sfVector2f	tmp;

	tmp.x = p->pos.x * 60;
	tmp.y = p->pos.y * 60;
	if (p->p == player1) {
		sfSprite_setPosition(p->assets[20].sprite, tmp);
		sfRenderWindow_drawSprite(p->window,
		p->assets[20].sprite, NULL);
	}
	else if (p->p == player2) {
		sfSprite_setPosition(p->assets[24].sprite, tmp);
		sfRenderWindow_drawSprite(p->window,
		p->assets[24].sprite, NULL);
	}
	else {
		sfSprite_setPosition(p->assets[23].sprite, tmp);
		sfRenderWindow_drawSprite(p->window,
		p->assets[23].sprite, NULL);
	}
}

void	update_attack(param_t *g)
{
	sfVector2f tmp = sfView_getCenter(g->view);

	tmp.x = tmp.x + 450;
	tmp.y = tmp.y - 200;
	if (g->fflower == 1) {
		sfSprite_setPosition(g->assets[30].sprite, tmp);
		sfRenderWindow_drawSprite(g->window,
		g->assets[30].sprite, NULL);
	}
}

void	update_score(param_t *g)
{
	sfTime time  = sfClock_getElapsedTime(g->g);
	static int	timer = 0;

	if (((int)sfTime_asSeconds(time) % 5) == 0 && !timer) {
		g->stats->life -= 2;
		timer = 1;
	} else if (((int)sfTime_asSeconds(time) % 10) == 4)
		timer = 0;
	sfVector2f	tmp = sfView_getCenter(g->view);
	display(g, "HP", (sfVector2f){tmp.x + 400, tmp.y - 300}, 50);
	display(g, score_to_string(g->stats->life),
	(sfVector2f){tmp.x + 500, tmp.y - 300}, 50);
}

void	update_game(param_t *g)
{
	sfVector2f	tmp;

	tmp.x = g->pos.x * 60;
	tmp.y = g->pos.y * 60;
	sfView_setCenter(g->view, tmp);
	sfRenderWindow_setView(g->window, g->view);
	update_score(g);
	update_attack(g);
}
