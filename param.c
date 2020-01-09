/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	finalbos_map(param_t *param)
{
	char *str[] = {"#####RRRRRRRRRRRRRRRRRRRR#####",
			"#####R#RR#R#RR#R##RR#R#R#R#####",
			"#####RR#RRR#R#RRRR#R#RRRR#####",
			"#####RRR##RRRRRR#RRRRRR#R#R###",
			"#####R#RRR#R#R#RRRRR#RRR#R####",
			"#####R#RRR#R#R#RRRRR#RRR#R####",
			"#####RR##RRRRRR#RR#RR##RR#####",
			"#####RRRR#R#R#RR#RR#RRR#R#####",
			"######R##RRRRRR#R#RRR#RRRR#####",
			"#####RRR#R#R#RRRRR#RR#RRR#####",
			"#####R#RRRR#RR#RRRR#RRR#R#####",
			"#####RR#R#RR#RRRR#RR##RRR#####",
			"######RRRR#RRR#R##RRRR#R######",
			"#####RR#RRR#R#RRRRR##RRRR#####",
			"#####R#RR#R#RRR#R#RRR#R#R#####",
			"#####RRR#RRRR#RRRRR#RRRR######",
			"############################", NULL};
	copy_map(str, param);
}

void	init_keys_sound_anim(param_t *param)
{
	set_default_values(param);
	init_keys(param);
	init_sound(param);
	init_anim(param);
	param->assets = initiate_assets_struct();
	initiate_assets(param);
}

void	init_sound1(param_t *param)
{
	param->hurt = sfSound_create();
	param->soundbuffer_hurt =
	sfSoundBuffer_createFromFile("assets/hurt.wav");
	sfSound_setBuffer(param->hurt, param->soundbuffer_hurt);
	param->laugh = sfSound_create();
	param->soundbuffer_laugh =
	sfSoundBuffer_createFromFile("assets/laugh.wav");
	sfSound_setBuffer(param->laugh, param->soundbuffer_laugh);
	finalbos_map(param);
}

param_t	*initiate_params(void)
{
	param_t	*param = my_malloc(sizeof(param_t));
	sfVideoMode	mode = {1920, 1080, 32};
	char	const	*title = "My RBG";

	param->window = sfRenderWindow_create(mode, title, sfClose, NULL);
	param->state = gameWait;
	param->fire = 0;
	param->text = sfText_create();
	sfRenderWindow_setFramerateLimit(param->window, 60);
	sfRenderWindow_setMouseCursorVisible(param->window, sfTrue);
	sfFloatRect test = configure_float_rect(0, 0, 1920, 1080);
	param->view = sfView_createFromRect(test);
	param->map = get_map("map");
	param->pos = locate_player(param);
	param->rect = configure_int_rect(0, 0, 60, 60);
	init(param);
	init_keys_sound_anim(param);
	return (param);
}
