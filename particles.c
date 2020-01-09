/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>
# include <string.h>

void	new_PartBuffer(int size, param_t *p)
{
	const size_t	size_m = ((sizeof(partBuffer) + sizeof(sfVertex)) *
				(size * 4) + sizeof(t_info) * size);
	void	*ptn = malloc(size_m);

	if (ptn == NULL)
		return;
	memset(ptn, 0, size_m);
	p->this = (partBuffer*)(ptn);
	p->this->size = size;
	p->this->vertex = (sfVertex*)(ptn + sizeof(partBuffer));
	p->this->info = (t_info *)(p->this->vertex + (size * 4));
}

void	drawPartBuffer(param_t *p)
{
	sfRenderWindow_drawPrimitives(p->window, p->this->vertex,
	p->this->size * 4, sfQuads, NULL);
}

void	setPart(param_t *p, uint id, sfVector2f pos, sfColor color)
{
	if (id >= p->this->size)
		return;
	p->this->vertex[(id * 4) + 0].position = (sfVector2f){pos.x + 0,
	pos.y + 0};
	p->this->vertex[(id * 4) + 1].position = (sfVector2f){pos.x + 10,
	pos.y + 0};
	p->this->vertex[(id * 4) + 2].position = (sfVector2f){pos.x + 10,
	pos.y + 10};
	p->this->vertex[(id * 4) + 3].position = (sfVector2f){pos.x + 0,
	pos.y + 10};
	p->this->vertex[(id * 4) + 0].color = color;
	p->this->vertex[(id * 4) + 1].color = color;
	p->this->vertex[(id * 4) + 2].color = color;
	p->this->vertex[(id * 4) + 3].color = color;
}

void	updatePartBuffer (param_t *p)
{
	for (uint id = 0 ; id < p->this->size ; id += 1) {
		p->this->vertex[(id * 4) + 0].position.x += 10;
		p->this->vertex[(id * 4) + 1].position.x += 10;
		p->this->vertex[(id * 4) + 2].position.x += 10;
		p->this->vertex[(id * 4) + 3].position.x += 10;
	}
}

void	init(param_t *param)
{
	int	w = 1920;
	int	h = 1080;

	new_PartBuffer(10000000, param);
	for ( uint i = 0 ; i <= 420 ; i ++) {
		setPart(param, i, (sfVector2f){rand () % w, rand() % h},
		(sfColor){rand() % 255, rand()%255, rand()%255, 255});
	}
}
