/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	set_play_settings(param_t *param)
{
	sfVector2f	pos;
	int	img1;
	int	img2;

	img1 = -1080;
	img2 = -1080;
	pos.x = 0;
	pos.y = 1080;
	if (sfSprite_getPosition(param->assets[21].sprite).y < img1)
		sfSprite_setPosition(param->assets[21].sprite, pos);
	else if (sfSprite_getPosition(param->assets[22].sprite).y < img2)
		sfSprite_setPosition(param->assets[22].sprite, pos);
}

void	move_settings(param_t *param)
{
	sfVector2f	map1;
	sfVector2f	map2;

	map1.x = 0;
	map1.y = -3;
	map2.x = 0;
	map2.y = -3;
	sfSprite_move(param->assets[21].sprite, map1);
	sfSprite_move(param->assets[22].sprite, map2);
}

void	settings_buttons(param_t *p)
{
	sfRenderWindow_drawSprite(p->window, p->assets[21].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[22].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[11].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[12].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[13].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[14].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[15].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[16].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[17].sprite, NULL);
	if (p->click->menu == 0)
		display_button(p, "BACK TO MENU", 600);
	else if (p->click->menu == 1)
		display_button(p, "> BACK TO MENU", 600);
	else
		display_button(p, ">> BACK TO MENU", 600);
	display_text(p, "PRES KEY 1", 50, 70);
	display_text(p, "PRES KEY 3", 50, 800);
	display_text(p, "PRES KEY 2", 50, 1480);
}

void	chose_player(param_t *p, sfVector2f pos,  sfVector2f pos2)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
		sfSprite_setPosition(p->assets[13].sprite, pos2);
		sfSprite_setPosition(p->assets[12].sprite, pos);
		sfSprite_setPosition(p->assets[14].sprite, pos);
		p->p = player1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
		sfSprite_setPosition(p->assets[12].sprite, pos2);
		sfSprite_setPosition(p->assets[13].sprite, pos);
		sfSprite_setPosition(p->assets[14].sprite, pos);
		p->p = player2;
	}
	if (sfKeyboard_isKeyPressed(sfKeyNum3)) {
		sfSprite_setPosition(p->assets[12].sprite, pos);
		sfSprite_setPosition(p->assets[13].sprite, pos);
		sfSprite_setPosition(p->assets[14].sprite, pos2);
		p->p = player3;
	}
}

void	draw_settings(param_t *p)
{
	sfVector2f	pos = set_value(-1920, -1080);
	sfVector2f	pos2 = set_value(830, 700);

	settings_buttons(p);
	display_charachter(p);
	sfRenderWindow_display(p->window);
	sfRenderWindow_clear(p->window, sfBlack);
	chose_player(p, pos, pos2);
}
