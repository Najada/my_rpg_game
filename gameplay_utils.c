/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	player_moving_animation(param_t *param)
{
	if (sfKeyboard_isKeyPressed(param->keys->up)) {
		title_rect2(param, param->anim->anm2);
		title_anim(param, param);
	}
	else if (sfKeyboard_isKeyPressed(param->keys->left)) {
		title_rect2_1(param, param->anim->anm2);
		title_anim(param, param);
	}
	if (sfKeyboard_isKeyPressed(param->keys->down)) {
		title_rect2_2(param, param->anim->anm2);
		title_anim(param, param);
	}
	else if (sfKeyboard_isKeyPressed(param->keys->right)) {
		title_rect2_3(param, param->anim->anm2);
		title_anim(param, param);
	}
}

void	player_attack_animation(param_t *param)
{
	if (sfKeyboard_isKeyPressed(param->keys->space) && param->fflower) {
		sfSound_play(param->attack);
		player_attacks(param);
		attack_rect(param, param->anim->anm2);
		attack_anim(param);
	}
	if (sfKeyboard_isKeyPressed(param->keys->c))
		check_flower(param);
	control_flower(param);
}

void	manage_inventary(param_t *param)
{
	if (sfKeyboard_isKeyPressed(param->keys->i)) {
		param->in = 1;
	}
	if (sfKeyboard_isKeyPressed(param->keys->u)) {
		param->in = 0;
	}
	if (param->in == 1) {
		sfVector2f tmp = {param->pos.x * 53.5, param->pos.y * 53.5};
		sfSprite_setPosition(param->assets[27].sprite, tmp);
		sfRenderWindow_drawSprite(param->window,
		param->assets[27].sprite, NULL);
	}
}

void	manage_fire(param_t *param)
{
	if (param->fire == 1) {
		draw_fire(param, param->anim->number);
		fire_anim(param);
	}
	if (sfClock_getElapsedTime(param->f).microseconds > 5000000) {
		param->fire = 1;
		sfClock_restart(param->f);
	}
	if (param->quest == Chicken) {
		chicken_quest(param);
	}
	if (param->quest == Banon) {
		banon_quest(param);
	}
	if (param->quest == Exit) {
		exit_quest(param);
	}
}

void	all_the_animations(param_t *param)
{
	sfRenderWindow_display(param->window);
	sfRenderWindow_clear(param->window, sfBlack);
	draw_map(param);
	enemy_rect(param, param->anim->anm2);
	enemy_anim(param, param);
	manage_fire(param);
	draw_player(param);
	my_close_ev(param);
	update_game(param);
	player_moving_animation(param);
	player_attack_animation(param);
	manage_inventary(param);
}
