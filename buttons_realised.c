/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	gamewait_realised(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 700 && mouse.y <= 850) {
		sfSleep(sfMilliseconds(150));
		sfRenderWindow_close(param->window);
	}
	else if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 550 && mouse.y <= 650)
		param->state = gameScore;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 250 && mouse.y <= 350)
		param->state = gameHow;
	else if (mouse.x >= 1200 && mouse.x <= 1600 &&
		mouse.y >= 100 && mouse.y <= 200)
		param->state = gameIntro;
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 400 && mouse.y <= 500)
		param->state = gameSettings;
}

void	gamepause_realised(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 50 && mouse.y <= 150)
		param->state = gameWait;
	else if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 700 && mouse.y <= 850) {
		sfSleep(sfMilliseconds(150));
		sfRenderWindow_close(param->window);
	}
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 400 && mouse.y <= 550)
		param->state = gamePlay;
}

void	gameintro_realised(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1600 && mouse.x <= 1800 &&
		mouse.y >= 900 && mouse.y <= 1000)
		param->state = gamePlay;
}

void	gamescore_realised(param_t *param, sfMouseButtonEvent mouse)
{
	if (mouse.x >= 1200 && mouse.x <= 1800 &&
		mouse.y >= 50 && mouse.y <= 150) {
		param->state = gameWait;
		param->click->menu = 0;
	}
}

void	game_realised(param_t *param, sfMouseButtonEvent mouse)
{
	if (param->state == gameHow) {
		if (mouse.x >= 1200 && mouse.x <= 1800 &&
			mouse.y >= 50 && mouse.y <= 150)
			param->state = gameWait;
	}
	else if (param->state == gameSettings) {
		if (mouse.x >= 1200 && mouse.x <= 1800 &&
			mouse.y >= 600 && mouse.y <= 750)
			param->state = gameWait;
	}
}
