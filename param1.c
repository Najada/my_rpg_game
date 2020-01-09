/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

void	init_click(param_t *param)
{
	param->click->play = 0;
	param->click->how = 0;
	param->click->settings = 0;
	param->click->quit = 0;
	param->click->score = 0;
	param->click->menu = 0;
	param->click->resume = 0;
	param->click->skip = 0;
	param->i = 0;
	param->in = 0;
}

void	init_anim(param_t *param)
{
	param->anim = malloc(sizeof(*param->anim));
	param->anim->number = 0;
	param->anim->anim = 0;
	param->anim->anm2 = 0;
	param->anim->animrect = 0;
	param->anim->anim2 = 0;
	param->anim->animrect2 = 0;
	param->anim->a = 0;
	param->anim->b2 = 0;
	param->anim->a1 = 0;
	param->anim->a2 = 0;
	param->anim->a3 = 0;
	param->fflower = 0;
}

void	init_keys(param_t *param)
{
	char	**keys = get_key("CONFIG_FILE");

	param->keys = malloc(sizeof(*param->keys));
	param->keys->u = my_getnbr(keys[0]);
	param->keys->i = my_getnbr(keys[1]);
	param->keys->c = my_getnbr(keys[2]);
	param->keys->space = my_getnbr(keys[3]);
	param->keys->up = my_getnbr(keys[4]);
	param->keys->left = my_getnbr(keys[5]);
	param->keys->down = my_getnbr(keys[6]);
	param->keys->right = my_getnbr(keys[7]);
	free_map(keys);
}

void	set_default_values(param_t *param)
{
	param->click = malloc(sizeof(*param->click));
	init_click(param);
	param->p = player1;
	param->stats = malloc(sizeof(*param->stats));
	param->enemy = malloc(sizeof(*param->enemy));
	param->stats->luck = 1;
	param->stats->inteligence = 4;
	param->stats->strength = 3;
	param->stats->defence = 2;
	param->stats->dexterity = 1;
	param->stats->life = 1000;
	param->enemy->a = 0;
	param->enemy->b = 0;
	param->enemy->c = 0;
	param->enemy->d = 0;
	param->enemy->e = 0;
	param->enemy->f = 0;
	param->enemy->bos = 0;
}

void	init_sound(param_t *param)
{
	param->click_sound = sfSound_create();
	param->soundbuffer_click =
	sfSoundBuffer_createFromFile("assets/menu.wav");
	sfSound_setBuffer(param->click_sound, param->soundbuffer_click);
	param->game = sfSound_create();
	param->soundbuffer_game =
	sfSoundBuffer_createFromFile("assets/game.wav");
	sfSound_setBuffer(param->game, param->soundbuffer_game);
	sfSound_setLoop(param->game, sfTrue);
	param->attack = sfSound_create();
	param->soundbuffer_attack =
	sfSoundBuffer_createFromFile("assets/sword.wav");
	sfSound_setBuffer(param->attack, param->soundbuffer_attack);
	param->death = sfSound_create();
	param->soundbuffer_death =
	sfSoundBuffer_createFromFile("assets/death.wav");
	sfSound_setBuffer(param->death, param->soundbuffer_death);
	init_sound1(param);
}
