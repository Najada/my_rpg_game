/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	display_time(param_t *param, char *str, sfVector2f tmp)
{
	sfText *text = param->text;

	sfText_setPosition(text, tmp);
	sfText_setString(text, str);
	sfText_setFont(text, param->default_font);
	sfText_setCharacterSize(text, 80);
	sfText_setColor(text, sfWhite);
	sfRenderWindow_drawText(param->window, text, NULL);
}

void	display_time_score(param_t *param, sfVector2f tmp)
{
	char	*str;

	float time  = sfTime_asSeconds(sfClock_getElapsedTime(param->c));
	str = score_to_string((int)(time/3600));
	display_time(param, str, (sfVector2f){tmp.x - 200, tmp.y});
	display_time(param, ":", (sfVector2f){tmp.x - 150, tmp.y});
	str = score_to_string((int)(time/60));
	display_time(param, str, (sfVector2f){tmp.x - 100, tmp.y});
	display_time(param, ":", (sfVector2f){tmp.x - 50, tmp.y});
	int t = (int)time;
	t = t % 60;
	str = score_to_string((t));
	display_time(param, str, (sfVector2f){tmp.x, tmp.y});
}
