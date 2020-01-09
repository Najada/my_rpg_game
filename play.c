/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	simple_rect(param_t *g, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(64 * anim, 0, 64, 64);
	sfSprite_setTextureRect(g->assets[20].sprite, rect2);
	sfSprite_setTextureRect(g->assets[24].sprite, rect2);
	sfSprite_setTextureRect(g->assets[23].sprite, rect2);
}

void	title_rect2(param_t *g, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(64 * anim, 64 * 8, 64, 64);
	if (g->p == player1)
		sfSprite_setTextureRect(g->assets[20].sprite, rect2);
	else if (g->p == player2)
		sfSprite_setTextureRect(g->assets[24].sprite, rect2);
	else
		sfSprite_setTextureRect(g->assets[23].sprite, rect2);
}

void	title_rect2_1(param_t *g, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(64 * anim, 64 * 9, 64, 64);
	if (g->p == player1)
		sfSprite_setTextureRect(g->assets[20].sprite, rect2);
	else if (g->p == player2)
		sfSprite_setTextureRect(g->assets[24].sprite, rect2);
	else
		sfSprite_setTextureRect(g->assets[23].sprite, rect2);
}

void	title_rect2_2(param_t *g, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(64 * anim, 64 * 10, 64, 64);
	if (g->p == player1)
		sfSprite_setTextureRect(g->assets[20].sprite, rect2);
	else if (g->p == player2)
		sfSprite_setTextureRect(g->assets[24].sprite, rect2);
	else
		sfSprite_setTextureRect(g->assets[23].sprite, rect2);
}

void	title_rect2_3(param_t *g, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(64 * anim, 64 * 11, 64, 64);
	if (g->p == player1)
		sfSprite_setTextureRect(g->assets[20].sprite, rect2);
	else if (g->p == player2)
		sfSprite_setTextureRect(g->assets[24].sprite, rect2);
	else
		sfSprite_setTextureRect(g->assets[23].sprite, rect2);
}
