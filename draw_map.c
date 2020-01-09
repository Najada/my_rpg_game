/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

static void	draw1(param_t *p, char c)
{
	if (c == ' ' || c == 'P' )
		p->rect = configure_int_rect(60, 0, 60, 60);
	else if (c == 'R')
		p->rect = configure_int_rect(260, 0, 60, 60);
	if (c == 'J')
		p->rect = configure_int_rect(450, 0, 60, 60);
	else if (c == 'V')
		p->rect = configure_int_rect(390, 0, 60, 60);
	if (c == 'G')
		p->rect = configure_int_rect(3, 64, 60, 60);
	else if (c == 'L')
		p->rect = configure_int_rect(60, 64, 60, 60);
	if (c == 'M') {
		if (p->i == 0)
			p->rect = configure_int_rect(60, 64, 60, 60);
		else
			p->rect = configure_int_rect(128, 133, 60, 60);
	}
}

static void	draw2(param_t *p, char c)
{
	if (c == '#')
		p->rect = configure_int_rect(126, 64, 60, 60);
	else if (c == '1')
		p->rect = configure_int_rect(0, 128, 60, 60);
	if (c == '2')
		p->rect = configure_int_rect(60, 128, 60, 60);
	else if (c == '3')
		p->rect = configure_int_rect(0, 188, 60, 60);
	if (c == '4')
		p->rect = configure_int_rect(60, 188, 60, 60);
	else if (c == '5')
		p->rect = configure_int_rect(3, 257, 60, 60);
	if (c == '6')
		p->rect = configure_int_rect(63, 257, 60, 60);
	else if (c == '7')
		p->rect = configure_int_rect(3, 317, 60, 60);
	if (c == '8')
		p->rect = configure_int_rect(63, 317, 60, 60);
}

static void	draw3(param_t *p, char c)
{
	if (c == '&')
		p->rect = configure_int_rect(324, 62, 60, 60);
	else if (c == '~')
		p->rect = configure_int_rect(384, 62, 60, 60);
	if (c == '(')
		p->rect = configure_int_rect(444, 62, 60, 60);
	else if (c == '|')
		p->rect = configure_int_rect(504, 62, 60, 60);
	if (c == '+')
		p->rect = configure_int_rect(135, 258, 60, 60);
	else if (c == 'E')
		p->rect = configure_int_rect(132, 197, 60, 60);
}

void	draw_map_case(param_t *p, char c)
{
	draw1(p, c);
	draw2(p, c);
	draw3(p, c);
	sfSprite_setTextureRect(p->assets[18].sprite, p->rect);
	sfRenderWindow_drawSprite(p->window, p->assets[18].sprite, NULL);
}

void	draw_map(param_t *p)
{
	int	x = 0;
	int	y = 0;

	while (p->map && p->map[y]) {
		x = 0;
		p->p_map.y = y * 60;
		while (p->map[y][x]) {
			p->p_map.x = x * 60;
			sfSprite_setPosition(p->assets[18].sprite, p->p_map);
			draw_map_case(p, p->map[y][x]);
			x++;
		}
		y++;
	}
}
