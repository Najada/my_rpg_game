/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	display_charachter(param_t *p)
{
	if (p->p == player1)
		display_text(p, SKILLS, 400, 70);
	else if (p->p == player2)
		display_text(p, SKILLS1, 400, 70);
	else
		display_text(p, SKILLS2, 400, 70);
}

void	my_title_settings(param_t *param, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(600 * anim, 0, 600, 672);
	sfSprite_setTextureRect(param->assets[11].sprite, rect2);
}

void	my_title_anim_settings(param_t *param)
{
	if (sfClock_getElapsedTime(param->settings).microseconds > 100000) {
		param->anim->a++;
		if (param->anim->a > 3)
			param->anim->a = 0;
		sfClock_restart(param->settings);
	}
}

void	my_title_settings2(param_t *param, int anim)
{
	sfIntRect	rect2;

	rect2 = configure_int_rect(187 * anim, 0, 187, 198);
	sfSprite_setTextureRect(param->assets[12].sprite, rect2);
}

void	my_title_anim_settings2(param_t *param)
{
	if (sfClock_getElapsedTime(param->settings2).microseconds > 100000) {
		param->anim->a1++;
		if (param->anim->a1 > 6)
			param->anim->a1 = 0;
		sfClock_restart(param->settings2);
	}
}
