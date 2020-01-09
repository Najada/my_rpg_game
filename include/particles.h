/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# ifndef _PARTICLES_H_
# define _PARTICLES_H_

# include <rpg.h>

typedef unsigned int uint;

void	new_PartBuffer(int size, param_t *p);
void	drawPartBuffer(param_t *p);
void	setPart(param_t *p, uint id, sfVector2f pos, sfColor color);
void updatePartBuffer (param_t *p);
void	init(param_t *param);
void	update(param_t *p);
# endif // _PARTICLES_H_
