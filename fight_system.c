/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

static void	attack1(param_t *param)
{
	if (param->map[param->pos.y - 1][param->pos.x] == 'a') {
		param->enemy->a = param->enemy->a + 1;
		if (param->enemy->a > 40) {
			sfSound_play(param->death);
			param->map[param->pos.y - 1][param->pos.x] = '+';
		}
	}
	else if (param->map[param->pos.y - 1][param->pos.x] == 'b') {
		param->enemy->b = param->enemy->b + 1;
		if (param->enemy->b > 40) {
			param->map[param->pos.y - 1][param->pos.x] = '+';
			sfSound_play(param->death);
		}
	}
}

static void	attack3(param_t *param)
{
	if (param->map[param->pos.y - 1][param->pos.x] == 'c') {
		param->enemy->c = param->enemy->c + 1;
		if (param->enemy->c > 40) {
			param->map[param->pos.y - 1][param->pos.x] = '+';
			sfSound_play(param->death);
		}
	}
	else if (param->map[param->pos.y - 1][param->pos.x] == 'd') {
		param->enemy->d = param->enemy->d + 1;
		if (param->enemy->d > 40) {
			param->map[param->pos.y - 1][param->pos.x] = '+';
			sfSound_play(param->death);
		}
	}
}

static	void	attack2(param_t *param)
{
	if (param->map[param->pos.y - 1][param->pos.x] == 'e') {
		param->enemy->e = param->enemy->e + 1;
		if (param->enemy->e > 40) {
			sfSound_play(param->death);
			param->map[param->pos.y - 1][param->pos.x] = '+';
		}
	}
	else if (param->map[param->pos.y - 1][param->pos.x] == 'f') {
		param->enemy->f = param->enemy->f + 1;
		if (param->enemy->f > 40) {
			param->map[param->pos.y - 1][param->pos.x] = '+';
			sfSound_play(param->death);
		}
	}
}

void	player_attacks(param_t *param)
{
	attack1(param);
	attack2(param);
	attack3(param);
}
