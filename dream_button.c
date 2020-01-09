/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	dream_move(param_t *p, sfMouseMoveEvent m)
{
	if (m.x >= 1600 && m.x <= 1800 &&
		m.y >= 900 && m.y <= 1000)
		p->click->skip = 1;
	else
		p->click->skip = 0;
}

void	dream_realised(param_t *p, sfMouseButtonEvent m)
{
	if (m.x >= 1600 && m.x <= 1800 &&
		m.y >= 900 && m.y <= 1000)
		p->state = finalBos;
}

void	dream_clicked(param_t *p, sfMouseButtonEvent m)
{
	if (m.x >= 1600 && m.x <= 1800 &&
		m.y >= 900 && m.y <= 1000)
		p->click->skip = 2;
	else
		p->click->skip = 0;
	sfSound_play(p->click_sound);
}
