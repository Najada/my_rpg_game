/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	destroy_sound(param_t *param)
{
	sfSoundBuffer_destroy(param->soundbuffer_click);
	sfSound_destroy(param->click_sound);
	sfSoundBuffer_destroy(param->soundbuffer_game);
	sfSound_destroy(param->game);
	sfSoundBuffer_destroy(param->soundbuffer_attack);
	sfSound_destroy(param->attack);
	sfSoundBuffer_destroy(param->soundbuffer_death);
	sfSound_destroy(param->death);
	sfSoundBuffer_destroy(param->soundbuffer_hurt);
	sfSound_destroy(param->hurt);
	sfSoundBuffer_destroy(param->soundbuffer_laugh);
	sfSound_destroy(param->laugh);
}

void	destroy_clock(param_t *param)
{
	sfClock_destroy(param->c);
	sfClock_destroy(param->c2);
	sfClock_destroy(param->tc);
	sfClock_destroy(param->settings);
	sfClock_destroy(param->settings2);
	sfClock_destroy(param->f);
	sfClock_destroy(param->settings3);
	sfClock_destroy(param->settings4);
	sfClock_destroy(param->player);
	sfClock_destroy(param->flower);
	sfClock_destroy(param->g);
}

void	destory_sprite_texture(param_t *param)
{
	for (int i = 0; i < ASSETS_CNT; i++) {
		sfSprite_destroy(param->assets[i].sprite);
		sfTexture_destroy(param->assets[i].texture);
	}
}

void	free_map(char **map)
{
	for (int i = 0 ; map[i] ; i++)
		free(map[i]);
	free(map);
}

void	my_free(param_t *param)
{
	destroy_sound(param);
	destroy_clock(param);
	destory_sprite_texture(param);
	sfText_destroy(param->text);
	sfFont_destroy(param->default_font);
	free(param->click);
	sfView_destroy(param->view);
	free(param->stats);
	free(param->enemy);
	free(param->keys);
	free(param->anim);
	free(param->this);
	free_map(param->map);
	free_map(param->str);
	sfRenderWindow_destroy(param->window);
	free(param->assets);
	free(param);
}
