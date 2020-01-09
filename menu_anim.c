/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	my_title_rect(param_t *param, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(650 * anim , 0, 650, 1000);
	sfSprite_setTextureRect(param->assets[2].sprite, rect2);
}

void	my_title_anim(param_t *param)
{
	if (sfClock_getElapsedTime(param->c).microseconds > 100000) {
		param->anim->anim++;
		if (param->anim->anim > 2)
			param->anim->anim = 0;
		sfClock_restart(param->c);
	}
}

void	my_title_rect2(param_t *param, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(666 * anim , 0, 666, 1000);
	sfSprite_setTextureRect(param->assets[3].sprite, rect2);
}

void	my_title_anim2(param_t *param)
{
	if (sfClock_getElapsedTime(param->c2).microseconds > 100000) {
		param->anim->anim2++;
		if (param->anim->anim2 > 2)
			param->anim->anim2 = 0;
		sfClock_restart(param->c2);
	}
}

void	sprite_pos(param_t *param)
{
	sfVector2f	p2;
	sfVector2f	title_pos;
	sfVector2f	title_pos2;

	title_pos.x = -80;
	title_pos.y = 0;
	title_pos2.x = 1300;
	title_pos2.y = 0;
	p2.x = 0;
	p2.y = 1080;
	sfSprite_setPosition(param->assets[1].sprite, p2);
	sfSprite_setPosition(param->assets[2].sprite, title_pos);
	sfSprite_setPosition(param->assets[3].sprite, title_pos2);
}
