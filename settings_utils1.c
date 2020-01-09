/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	my_title_settings3(param_t *param, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(187 * anim, 0, 187, 198);
	sfSprite_setTextureRect(param->assets[13].sprite, rect2);
}

void	my_title_anim_settings3(param_t *param)
{
	if (sfClock_getElapsedTime(param->settings3).microseconds > 100000) {
		param->anim->a2++;
		if (param->anim->a2 > 6)
			param->anim->a2 = 0;
		sfClock_restart(param->settings3);
	}
}

void	my_title_settings4(param_t *param, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(187 * anim, 0, 187, 198);
	sfSprite_setTextureRect(param->assets[14].sprite, rect2);
}

void	my_title_anim_settings4(param_t *param)
{
	if (sfClock_getElapsedTime(param->settings4).microseconds > 100000) {
		param->anim->a3++;
		if (param->anim->a3 > 6)
			param->anim->a3 = 0;
		sfClock_restart(param->settings4);
	}
}

void	sprite_pos_settings(param_t *param)
{
	sfVector2f	title_pos = set_value(630, 300);
	sfVector2f	title_pos2 = set_value(830, 700);
	sfVector2f	pos3 = set_value(-500, 0);
	sfVector2f	pos4 = set_value(-500, 0);
	sfVector2f	cus1 = set_value(400, 0);
	sfVector2f	cus2 = set_value(1100, 0);
	sfVector2f	cus3 = set_value(1800, 0);
	sfVector2f	p2 = set_value(0, 1800);

	sfSprite_setPosition(param->assets[21].sprite, p2);
	sfSprite_setPosition(param->assets[11].sprite, title_pos);
	sfSprite_setPosition(param->assets[12].sprite, title_pos2);
	sfSprite_setPosition(param->assets[13].sprite, pos3);
	sfSprite_setPosition(param->assets[14].sprite, pos4);
	sfSprite_setPosition(param->assets[15].sprite, cus1);
	sfSprite_setPosition(param->assets[16].sprite, cus2);
	sfSprite_setPosition(param->assets[17].sprite, cus3);
}
