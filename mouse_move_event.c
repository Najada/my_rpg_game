/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** my_cook
*/

# include <rpg.h>

static void	move_event(param_t *param, sfMouseMoveEvent mouse)
{
	if (param->state == gameWait)
		gamewait_move(param, mouse);
	else if (param->state == gameScore)
		gamescore_move(param, mouse);
	if (param->state == gamePause)
		gamepause_move(param, mouse);
	else if (param->state == gameIntro)
		gameintro_move(param, mouse);
	if (param->state == gameHow)
		gamehow_move(param, mouse);
	else if (param->state == gameSettings)
		gamesettings_move(param, mouse);
	if (param->state == gameDream)
		dream_move(param, mouse);
}

void	mouse_move_event(param_t *param, sfEvent event)
{
	if (event.type == sfEvtMouseMoved) {
		sfMouseMoveEvent mouse = event.mouseMove;
		move_event(param, mouse);
	}
}
