/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	set_play(param_t *param)
{
	sfVector2f	pos;
	int	img1;
	int	img2;

	img1 = -1080;
	img2 = -1080;
	pos.x = 0;
	pos.y = 1080;
	if (sfSprite_getPosition(param->assets[0].sprite).y < img1)
		sfSprite_setPosition(param->assets[0].sprite, pos);
	else if (sfSprite_getPosition(param->assets[1].sprite).y < img2)
		sfSprite_setPosition(param->assets[1].sprite, pos);
}

void	move(param_t *param)
{
	sfVector2f	map1;
	sfVector2f	map2;

	map1.x = 0;
	map1.y = -3;
	map2.x = 0;
	map2.y = -3;
	sfSprite_move(param->assets[0].sprite, map1);
	sfSprite_move(param->assets[1].sprite, map2);
}

static void	menu_buttons(param_t *param)
{
	if (param->click->play == 2)
		display_button(param, ">> PLAY", 100);
	else if (param->click->play == 0)
		display_button(param, "PLAY", 100);
	else
		display_button(param, "> PLAY", 100);
	if (param->click->how == 2)
		display_button(param, ">> HOW TO PLAY", 250);
	else if (param->click->how == 0)
		display_button(param, "HOW TO PLAY", 250);
	else
		display_button(param, "> HOW TO PLAY", 250);
	if (param->click->settings == 2)
		display_button(param, ">> SETTINGS", 400);
	else if (param->click->settings == 0)
		display_button(param, "SETTINGS", 400);
	else
		display_button(param, "> SETTINGS", 400);
}

static void	menu_buttons1(param_t *param)
{
	if (param->click->score == 2)
		display_button(param, ">> HIGH SCORE", 550);
	else if (param->click->score == 0)
		display_button(param, "HIGH SCORE", 550);
	else
		display_button(param, "> HIGH SCORE", 550);
	if (param->click->quit == 2)
		display_button(param, ">> QUIT", 700);
	else if (param->click->quit == 0)
		display_button(param, "QUIT", 700);
	else
		display_button(param, "> QUIT", 700);
}

void	draw_menu(param_t *param)
{
	sfRenderWindow_drawSprite(param->window, param->assets[0].sprite, NULL);
	sfRenderWindow_drawSprite(param->window, param->assets[1].sprite, NULL);
	sfRenderWindow_drawSprite(param->window, param->assets[2].sprite, NULL);
	sfRenderWindow_drawSprite(param->window, param->assets[3].sprite, NULL);
	menu_buttons(param);
	menu_buttons1(param);
	sfRenderWindow_display(param->window);
	sfRenderWindow_clear(param->window, sfYellow);
}
