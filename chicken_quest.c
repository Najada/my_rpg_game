/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	get_to_game(param_t *p, int *b, int *k)
{
	if (*b && sfKeyboard_isKeyPressed(sfKeyA)) {
		for (int i = 0 ; i < 9 ; i++)
			sfView_zoom(p->view, 1.1);
		p->quest = alien;
		*b = 0;
		*k = 0;
		p->map[p->pos.y - 1][p->pos.x] = ' ';
	}
}
