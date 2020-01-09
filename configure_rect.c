/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

sfIntRect	configure_int_rect(int left, int top, int width, int height)
{
	sfIntRect	rec;

	rec.left = left;
	rec.top = top;
	rec.width = width;
	rec.height = height;
	return (rec);
}

sfFloatRect	configure_float_rect(int left, int top, int w, int h)
{
	sfFloatRect	rec;

	rec.left = left;
	rec.top = top;
	rec.width = w;
	rec.height = h;
	return (rec);
}

sfVector2f	set_value(int x, int y)
{
	sfVector2f	tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp);
}
