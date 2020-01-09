/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# ifndef _BUTTONS_H_
# define _BUTTONS_H_

# include <rpg.h>

void	gamewait_buttons(param_t *, sfMouseButtonEvent);
void	gamescore_buttons(param_t *, sfMouseButtonEvent);
void	gamepause_buttons(param_t *, sfMouseButtonEvent);
void	gameintro_buttons(param_t *, sfMouseButtonEvent);
void	gamehow_buttons(param_t *, sfMouseButtonEvent);
void	gamesettings_buttons(param_t *, sfMouseButtonEvent);
void	gamewait_realised(param_t *, sfMouseButtonEvent);
void	gamepause_realised(param_t *, sfMouseButtonEvent);
void	gameintro_realised(param_t *, sfMouseButtonEvent);
void	gamescore_realised(param_t *, sfMouseButtonEvent);
void	game_realised(param_t *, sfMouseButtonEvent);
void	gamewait_move(param_t *, sfMouseMoveEvent);
void	gamepause_move(param_t *, sfMouseMoveEvent);
void	gamesettings_move(param_t *, sfMouseMoveEvent);
void	gamehow_move(param_t *, sfMouseMoveEvent);
void	gameintro_move(param_t *, sfMouseMoveEvent);
void	gamescore_move(param_t *, sfMouseMoveEvent);
void	dream_move(param_t *, sfMouseMoveEvent);
void	dream_realised(param_t *, sfMouseButtonEvent);
void	dream_clicked(param_t *, sfMouseButtonEvent);

# endif // _BUTTONS_H_
