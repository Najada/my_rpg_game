/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	display(param_t *param, char *str, sfVector2f pos1, int size)
{
	sfText	*text = param->text;

	sfText_setPosition(text, pos1);
	sfText_setString(text, str);
	sfText_setFont(text, param->default_font);
	sfText_setCharacterSize(text, size);
	sfText_setColor(text, sfWhite);
	sfRenderWindow_drawText(param->window, text, NULL);
}

void	display_text(param_t *param, char *str, int x, int y)
{
	sfText	*text = param->text;
	sfVector2f	pos1 = {y, x};

	sfText_setPosition(text, pos1);
	sfText_setString(text, str);
	sfText_setFont(text, param->default_font);
	sfText_setCharacterSize(text, 50);
	sfText_setColor(text, sfWhite);
	sfRenderWindow_drawText(param->window, text, NULL);
}
