/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	gamehow_move(param_t *param, sfMouseMoveEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 50 && mouse.y <= 150)
		param->click->menu = 1;
	else
		param->click->menu = 0;
}

void	gameintro_move(param_t *param, sfMouseMoveEvent mouse)
{
	if (mouse.x >= 1600 && mouse.x <= 1800 &&
		mouse.y >= 900 && mouse.y <= 1000)
		param->click->skip = 1;
	else
		param->click->skip = 0;
}

void	gamescore_move(param_t *param, sfMouseMoveEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 50 && mouse.y <= 150)
		param->click->menu = 1;
	else
		param->click->menu = 0;
}
