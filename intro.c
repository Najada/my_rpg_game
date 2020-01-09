/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	sprite_pos_intro(param_t *param)
{
	sfVector2f	p2;
	sfVector2f	i;

	p2.x = 1920;
	p2.y = 0;
	i.y = 1080;
	i.x = 0;
	sfSprite_setPosition(param->assets[9].sprite, p2);
	sfSprite_setPosition(param->assets[7].sprite, i);
}

void	set_play_intro(param_t *param)
{
	sfVector2f	pos;
	int	img1;
	int	img2;

	img1 = -1920;
	img2 = -1920;
	pos.x = 1920;
	pos.y = 0;
	if (sfSprite_getPosition(param->assets[8].sprite).x < img1) {
		sfSprite_setPosition(param->assets[8].sprite, pos);
	}
	else if (sfSprite_getPosition(param->assets[9].sprite).x < img2) {
		sfSprite_setPosition(param->assets[9].sprite, pos);
	}
}

void	move_intro(param_t *param)
{
	sfVector2f	map1, map2, txt;

	map1.x = -3;
	map1.y = 0;
	map2.x = -3;
	map2.y = 0;
	txt.x = 0;
	txt.y = -1;
	sfSprite_move(param->assets[8].sprite, map1);
	sfSprite_move(param->assets[9].sprite, map2);
	if (sfSprite_getPosition(param->assets[7].sprite).y == 0) {
		param->state = gamePlay;
		sfSleep(sfMilliseconds(1500));
		return;
	}
	sfSprite_move(param->assets[7].sprite, txt);
}

void	skip(param_t *param, char *str, int x, sfColor color)
{
	sfText	*text = param->text;
	sfVector2f	pos1 = {1600, x};

	sfText_setPosition(text, pos1);
	sfText_setString(text, str);
	sfText_setFont(text, param->default_font);
	sfText_setCharacterSize(text, 100);
	sfText_setColor(text, color);
	sfRenderWindow_drawText(param->window, text, NULL);
}

void	draw_intro(param_t *p)
{
	sfRenderWindow_drawSprite(p->window, p->assets[8].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[9].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[7].sprite, NULL);
	if (p->click->skip == 2)
		skip(p, "SKIP", 900, sfBlue);
	else if (p->click->skip == 0)
		skip(p, "SKIP", 900, sfWhite);
	else
		skip(p, "> SKIP", 900, sfWhite);
	sfRenderWindow_display(p->window);
	sfRenderWindow_clear(p->window, sfBlack);
}
