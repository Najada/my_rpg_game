/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

static void	click_buttons(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1600 &&
		mouse.y >= 100 && mouse.y <= 200)
		param->click->play = 2;
	else
		param->click->play = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 250 && mouse.y <= 350)
		param->click->how = 2;
	else
		param->click->how = 0;
}

static void	click_buttons1(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 400 && mouse.y <= 500)
		param->click->settings = 2;
	else
		param->click->settings = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 550 && mouse.y <= 650)
		param->click->score = 2;
	else
		param->click->score = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 700 && mouse.y <= 850)
		param->click->quit = 2;
	else
		param->click->quit = 0;
}

void	gamewait_buttons(param_t *param, sfMouseButtonEvent mouse)
{
	click_buttons(param, mouse);
	click_buttons1(param, mouse);
	sfSound_play(param->click_sound);
}

void	gamescore_buttons(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 50 && mouse.y <= 150)
		param->click->menu = 2;
	else
		param->click->menu = 0;
	sfSound_play(param->click_sound);
}

void	gamepause_buttons(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 50 && mouse.y <= 150)
		param->click->menu = 2;
	else
		param->click->menu = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 700 && mouse.y <= 850)
		param->click->quit = 2;
	else
		param->click->quit = 0;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 400 && mouse.y <= 550)
		param->click->resume = 2;
	else
		param->click->resume = 0;
	sfSound_play(param->click_sound);
}
