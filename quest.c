/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

static char	*put_string(int c)
{
	char	*str = NULL;

	if (c == 0)
		str = CHICKEN_QUEST;
	else if (c == 1)
		str = CHICKEN_WRONG;
	else
		str = CHICKEN_RIGHT;
	return (str);
}

static void	arrange_view(int *a, param_t *p)
{
	if (*a == 0) {
		for (int i = 0 ; i < 9 ; i++)
			sfView_zoom(p->view, 0.9);
		(*a)++;
	}
}

static void	array_value(param_t *p, int *k, int *b, int *c)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum5)) {
		p->i = 1;
		*c = 2;
		*b = 1;
		*k = 0;
	} else if (sfKeyboard_isKeyPressed(sfKeyNum1) ||
		sfKeyboard_isKeyPressed(sfKeyNum2) ||
		sfKeyboard_isKeyPressed(sfKeyNum3) ||
		sfKeyboard_isKeyPressed(sfKeyNum4)) {
		*c = 1;
		*b = 1;
		*k = 0;
	}
	get_to_game(p, b, k);
}

static void	display_sprite(param_t *p)
{
	sfVector2f tmp1;
	tmp1.x = p->pos.x * 30;
	tmp1.y = p->pos.y * 53.5;
	sfVector2f tmp2;
	tmp2.x = p->pos.x * 59.7;
	tmp2.y = p->pos.y * 58;
	sfSprite_setPosition(p->assets[25].sprite, tmp1);
	sfSprite_setPosition(p->assets[26].sprite, tmp2);
	sfRenderWindow_drawSprite(p->window, p->assets[25].sprite, NULL);
	sfRenderWindow_drawSprite(p->window, p->assets[26].sprite, NULL);
}

void	chicken_quest(param_t *p)
{
	static int 	a = 0, k = 0, b = 0, c = 0;
	char	*tmp = NULL;
	static char	*str = NULL;

	str = put_string(c);
	arrange_view(&a, p);
	if (sfClock_getElapsedTime(p->tc).microseconds > 10000) {
		if (str[k]) {
			k++;
			sfClock_restart(p->tc);
		}
	}
	tmp = my_strndup(str, k);
	display_sprite(p);
	display(p, tmp, (sfVector2f){p->pos.x * 54, p->pos.y * 56.5}, 12);
	free(tmp);
	array_value(p, &k, &b, &c);
}
