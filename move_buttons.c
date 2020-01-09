/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

static void	move_buttons(param_t *param, sfMouseMoveEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1600 &&
		mouse.y >= 100 && mouse.y <= 200)
		param->click->play = 1;
	else
		param->click->play = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 250 && mouse.y <= 350)
		param->click->how = 1;
	else
		param->click->how = 0;
}

static void	move_buttons1(param_t *param, sfMouseMoveEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 400 && mouse.y <= 500)
		param->click->settings = 1;
	else
		param->click->settings = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 550 && mouse.y <= 650)
		param->click->score = 1;
	else
		param->click->score = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 700 && mouse.y <= 850)
		param->click->quit = 1;
	else
		param->click->quit = 0;
}

void	gamewait_move(param_t *param, sfMouseMoveEvent mouse)
{
	move_buttons(param, mouse);
	move_buttons1(param, mouse);
}

void	gamepause_move(param_t *param, sfMouseMoveEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 50 && mouse.y <= 150)
		param->click->menu = 1;
	else
		param->click->menu = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 700 && mouse.y <= 850)
		param->click->quit = 1;
	else
		param->click->quit = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 400 && mouse.y <= 550)
		param->click->resume = 1;
	else
		param->click->resume = 0;
}

void	gamesettings_move(param_t *param, sfMouseMoveEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 600 && mouse.y <= 750)
		param->click->menu = 1;
	else
		param->click->menu = 0;
}
