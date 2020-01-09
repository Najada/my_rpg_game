/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	gameintro_buttons(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1600 && mouse.x <= 1800 &&
		mouse.y >= 900 && mouse.y <= 1000)
		param->click->skip = 2;
	else
		param->click->skip = 0;
	sfSound_play(param->click_sound);
}

void	gamehow_buttons(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 50 && mouse.y <= 150)
		param->click->menu = 2;
	else
		param->click->menu = 0;
	sfSound_play(param->click_sound);
}

void	gamesettings_buttons(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 600 && mouse.y <= 750)
		param->click->menu = 2;
	else
		param->click->menu = 0;
	sfSound_play(param->click_sound);
}
