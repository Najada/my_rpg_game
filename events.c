/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** events functions
*/

# include <rpg.h>

void	my_close_ev(param_t *param)
{
	sfEvent	event;

	while (sfRenderWindow_pollEvent(param->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(param->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
			param->state == gamePlay)
			param->state = gamePause;
		events_manager(param, event);
		if (param->quest == alien)
			move_player(param);
	}
}

void	mouse_event(param_t *param, sfEvent event)
{
	mouse_move_event(param, event);
	mouse_click_event(param, event);
}

void	events_manager(param_t *param, sfEvent event)
{
	mouse_event(param, event);
}
