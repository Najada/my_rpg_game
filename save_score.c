/*
** EPITECH PROJECT, 2018
** rp
** File description:
** rpg
*/

# include <rpg.h>

void	save_score(param_t *p)
{
	FILE	*stream = NULL;

	if (p->state == gameWin) {
		char	*str = read_file("score");
		if (my_getnbr(str) > p->stats->life)
			return;
		else {
			stream = fopen("score", "w+");
			fwrite(score_to_string(p->stats->life),
			sizeof(score_to_string(p->stats->life)),
			my_strlen(score_to_string(p->stats->life)),  stream);
			fclose(stream);
		}
	}
}

void	manage_quest(param_t *g)
{
	if (g->map[g->pos.y - 1][g->pos.x] == '~')
		g->quest  = Chicken;
	else if (g->map[g->pos.y - 1][g->pos.x] == '&')
		g->quest  = Banon;
	if (g->map[g->pos.y - 1][g->pos.x] == '(')
		g->quest  = Exit;
	else if (g->map[g->pos.y - 1][g->pos.x] == 'E')
		g->state = gameDream;
}

void	copy_map(char *str[], param_t *param)
{
	int	i;

	param->str = malloc(sizeof(*param->str) * 20);
	for (i = 0 ; str[i] ; i++)
		param->str[i] = my_strdup(str[i]);
	param->str[i] = NULL;
}
