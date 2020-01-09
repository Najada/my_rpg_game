/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

static void	pause_buttons(param_t *param)
{
	if (param->click->menu == 0)
		display_button(param, "BACK TO MENU", 50);
	else if (param->click->menu == 1)
		display_button(param, "> BACK TO MENU", 50);
	else
		display_button(param, ">> BACK TO MENU", 50);
	if (param->click->quit == 2)
		display_button(param, ">> QUIT", 700);
	else if (param->click->quit == 0)
		display_button(param, "QUIT", 700);
	else
		display_button(param, "> QUIT", 700);
	if (param->click->resume == 2)
		display_button(param, ">> RESUME", 400);
	else if (param->click->resume == 0)
		display_button(param, "RESUME", 400);
	else
		display_button(param, "> RESUME", 400);
}

void	game_pause(param_t *param)
{
	sfFloatRect	test;

	sfView_destroy(param->view);
	test = configure_float_rect(0, 0, 1920, 1080);
	param->view = sfView_createFromRect(test);
	sfRenderWindow_setView(param->window, param->view);
	sfRenderWindow_drawSprite(param->window, param->assets[6].sprite, NULL);
	pause_buttons(param);
	sfRenderWindow_display(param->window);
	sfRenderWindow_clear(param->window, sfBlack);
}
