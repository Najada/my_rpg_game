/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** my_cook
*/

# include <rpg.h>

static void	mouse_click(param_t *param, sfMouseButtonEvent mouse)
{
	if (param->state == gameWait)
		gamewait_buttons(param, mouse);
	else if (param->state == gameScore)
		gamescore_buttons(param, mouse);
	if (param->state == gamePause)
		gamepause_buttons(param, mouse);
	else if (param->state == gameIntro)
		gameintro_buttons(param, mouse);
	if (param->state == gameHow)
		gamehow_buttons(param, mouse);
	else if (param->state == gameSettings)
		gamesettings_buttons(param, mouse);
	if (param->state == gameDream)
		dream_clicked(param, mouse);
}

static void	mouse_realised(param_t *param, sfMouseButtonEvent mouse)
{
	if (param->state == gameWait)
		gamewait_realised(param, mouse);
	else if (param->state == gameScore)
		gamescore_realised(param, mouse);
	if (param->state == gamePause)
		gamepause_realised(param, mouse);
	else if (param->state == gameIntro)
		gameintro_realised(param, mouse);
	if (param->state == gameDream)
		dream_realised(param, mouse);
	game_realised(param, mouse);
}

void	mouse_click_event(param_t *param, sfEvent event)
{
	if (event.type == sfEvtMouseButtonPressed) {
		sfMouseButtonEvent mouse = event.mouseButton;
		mouse_click(param, mouse);
	} else if (event.type == sfEvtMouseButtonReleased) {
		sfMouseButtonEvent mouse = event.mouseButton;
		mouse_realised(param, mouse);
	}
}
