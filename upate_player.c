/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

sfVector2i	locate_player(param_t *p)
{
	char	**tmp = p->map;
	sfVector2i	pos;

	pos.x = -1;
	pos.y = -1;
	for (int i = 0 ; tmp[i] ; i++) {
		for (int j = 0 ; tmp[i][j] ; j++) {
			if (tmp[i][j] == 'P') {
				pos.y = i;
				pos.x = j;
				return (pos);
			}
		}
	}
	return (pos);
}

int	check_move(param_t *g, int y, int x)
{
	if (g->map[y][x] == ' ' ||
		g->map[y][x] == 'L' ||
		g->map[y][x] == 'M')
		return (1);
	return (0);
}

void	move_up_down(param_t *g)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		if (check_move(g, g->pos.y + 1, g->pos.x))
			g->pos.y++;
	} else if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		if (check_move(g, g->pos.y - 1, g->pos.x))
			g->pos.y--;
		else
			manage_quest(g);
	}
}

void	move_left_right(param_t *g)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		if (check_move(g, g->pos.y, g->pos.x - 1))
			g->pos.x--;
	}
	else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		if (check_move(g, g->pos.y, g->pos.x + 1))
			g->pos.x++;
	}
}

void	move_player(param_t *g)
{
	if (g->state == gamePlay) {
		move_up_down(g);
		move_left_right(g);
	} else if (g->state == finalBos)
		move_finalbos(g);
}
