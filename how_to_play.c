/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	game_how(param_t *param)
{
	sfRenderWindow_display(param->window);
	sfRenderWindow_clear(param->window, sfBlack);
	sfRenderWindow_drawSprite(param->window, param->assets[10].sprite,
	NULL);
	if (param->click->menu == 0)
		display_button(param, "BACK TO MENU", 50);
	else if (param->click->menu == 1)
		display_button(param, "> BACK TO MENU", 50);
	else
		display_button(param, ">> BACK TO MENU", 50);
}
