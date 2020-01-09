/*
** EPITECH PROJECT, 2018
** rph
** File description:
** rpg
*/

# include <rpg.h>

char	*read_file(char *str)
{
	FILE	*stream;
	char	*line = NULL;
	size_t	len = 0;

	stream = fopen(str, "r");
	if (stream == NULL)
		return (NULL);
	getline(&line, &len, stream);
		fclose(stream);
	return (line);
}

void	high_score(param_t *param, char *str)
{
	sfText	*text = param->text;
	sfVector2f	pos1 = {800, 800};
	char	*line = read_file(str);

	sfText_setPosition(text, pos1);
	sfText_setString(text, line);
	sfText_setFont(text, param->default_font);
	sfText_setCharacterSize(text, 100);
	sfText_setColor(text, sfCyan);
	sfRenderWindow_drawText(param->window, text, NULL);
}

void	game_score(param_t *param)
{
	sfRenderWindow_display(param->window);
	sfRenderWindow_clear(param->window, sfYellow);
	sfRenderWindow_drawSprite(param->window,
	param->assets[5].sprite, NULL);
	high_score(param, "score");
	if (param->click->menu == 0)
		display_button(param, "BACK TO MENU", 50);
	else if (param->click->menu == 1)
		display_button(param, "> BACK TO MENU", 50);
	else
		display_button(param, ">> BACK TO MENU", 50);
}
