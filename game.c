/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	gamewait_state(param_t *param)
{
	if (param->state == gameWait) {
		draw_menu(param);
		set_play(param);
		move(param);
		my_title_rect(param, param->anim->anim);
		my_title_anim(param);
		my_title_rect2(param, param->anim->anim2);
		my_title_anim2(param);

	}
}

void	gamescore_pause(param_t *param, int *n)
{
	if (param->state == gameScore)
		game_score(param);
	else if (param->state == gamePause) {
		game_pause(param);
		*n = 0;
	}
	if (param->state == gameIntro) {
		sfSound_play(param->game);
		draw_intro(param);
		set_play_intro(param);
		move_intro(param);
	}
	else if (param->state == gameHow)
		game_how(param);
}

void	game_settings(param_t *param)
{
	if (param->state == gameSettings) {
		draw_settings(param);
		set_play_settings(param);
		move_settings(param);
		my_title_settings(param, param->anim->a);
		my_title_anim_settings(param);
		my_title_settings2(param, param->anim->a1);
		my_title_anim_settings2(param);
		my_title_settings3(param, param->anim->a2);
		my_title_anim_settings3(param);
		my_title_settings4(param, param->anim->a3);
		my_title_anim_settings4(param);
	}
}

void	gameplay_state(param_t *param, int *n)
{
	if (param->state == gamePlay) {
		if (*n == 0) {
			sfVector2f tmp;
			tmp.x = param->pos.x * 60;
			tmp.y = param->pos.y * 60;
			sfView_setCenter(param->view, tmp);
			sfRenderWindow_setView(param->window, param->view);
			sfView_zoom(param->view, 0.9);
			sfView_zoom(param->view, 0.9);
			sfView_zoom(param->view, 0.9);
			sfView_zoom(param->view, 0.9);
			(*n)++;
		}
		all_the_animations(param);
		is_finished(param);
	}

}

void	game_loader(param_t *param, int *n)
{
	gamewait_state(param);
	gamescore_pause(param, n);
	game_settings(param);
	gameplay_state(param, n);
	gameend_state(param);
	gamewin_state(param);
	gamedream_state(param);
	finalbos_state(param);
}
