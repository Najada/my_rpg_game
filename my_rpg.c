/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	init_clock(param_t *param)
{
	param->c = sfClock_create();
	param->c2 = sfClock_create();
	param->tc = sfClock_create();
	param->settings = sfClock_create();
	param->settings2 = sfClock_create();
	param->f = sfClock_create();
	param->settings3 = sfClock_create();
	param->settings4 = sfClock_create();
	param->player = sfClock_create();
	param->flower = sfClock_create();
	param->g = sfClock_create();
}

void	set_intial_position(param_t *param)
{
	simple_rect(param, param->anim->anm2);
	sprite_pos_settings(param);
	sprite_pos_intro(param);
	sprite_pos(param);
}

int	my_rpg(param_t *param)
{
	static	int	n = 0;

	set_intial_position(param);
	init_clock(param);
	while (sfRenderWindow_isOpen(param->window)) {
		my_close_ev(param);
		game_loader(param, &n);
	}
	return (0);
}
