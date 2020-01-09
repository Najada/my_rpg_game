/*
** EPITECH PROJECT, 2018
** joan
** File description:
** joan
*/

#include <library.h>
#ifndef	_RPG_H_
#define	_RPG_H_
#define	ASSETS_CNT 32
#define	ENEMY_CNT 10
#include <dialogue.h>

sfIntRect	configure_int_rect(int left, int top, int width, int height);
sfFloatRect	configure_float_rect(int, int, int, int);
sfVector2f	set_value(int x, int y);
typedef FILE	file;
#define	SKILLS	"\
LUCK		1/5\n\n\
INTELIGENCE	4/5\n\n\
STRENGTH	3/5\n\n\
DEXTERITY	1/5\n\n\
DEFENCE		2/5\n\n"

#define	SKILLS1	"\
LUCK		4/5\n\n\
INTELIGENCE	2/5\n\n\
STRENGTH	4/5\n\n\
DEXTERITY	1/5\n\n\
DEFENCE		1/5\n\n"

#define	SKILLS2	"\
LUCK		3/5\n\n\
INTELIGENCE	3/5\n\n\
STRENGTH	3/5\n\n\
DEXTERITY	3/5\n\n\
DEFENCE		4/5\n\n"

void	free_map(char **map);
#include <SFML/System/Export.h>
typedef	struct	assets {
	sfIntRect	*rec;
	sfTexture	*texture;
	sfSprite	*sprite;
}	assets_t;

typedef	enum	state {
	gameWait,
	gamePlay,
	gameEnd,
	gamePause,
	gameScore,
	gameIntro,
	gameHow,
	gameSettings,
	gameDream,
	gameWin,
	finalBos
}	state_e;

typedef	enum	player {
	player1,
	player2,
	player3,
}	player_e;

typedef	enum	quest {
	alien,
	Chicken,
	Banon,
	Exit
}	quest_e;

typedef	struct	keys {
	int	space;
	int	escape;
	int	up;
	int	down;
	int	left;
	int	right;
	int	i;
	int	u;
	int	a;
	int	c;
}	keys_t;

typedef	struct	anim {
	int	number;
	int	anim;
	int	anm2;
	int	animrect;
	int	anim2;
	int	animrect2;
	int	a;
	int	b2;
	int	a1;
	int	a2;
	int	a3;
}	anim_t;

typedef struct	enemy {
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
	int	f;
	int	bos;
}	enemy_t;

typedef	struct	mouse {
	int	play;
	int	how;
	int	settings;
	int	quit;
	int	score;
	int	menu;
	int	resume;
	int	skip;
}	mouse_t;

typedef	struct	stats {
	int	inteligence;
	int	luck;
	int	strength;
	int	dexterity;
	int	defence;
	int	life;
}	stats_t;

typedef struct s_info
{
sfVector2f speed ;
} t_info ;

typedef struct s_partBUffer
{
	sfVertex	*vertex;
	uint	size;
	t_info * info ;
} partBuffer;


typedef	struct	params {

	sfRenderWindow	*window;
	const	sfView	*fixedView;
	assets_t	*assets;
	sfText	*text;
	sfFont	*default_font;
	state_e	state;
	sfSound	*click_sound;
	sfSoundBuffer	*soundbuffer_click;
	sfSound	*game;
	sfSoundBuffer	*soundbuffer_game;
	sfSound	*attack;
	sfSoundBuffer	*soundbuffer_attack;
	sfSound	*death;
	sfSoundBuffer	*soundbuffer_death;
	sfSound	*hurt;
	sfSoundBuffer	*soundbuffer_hurt;
	sfSound	*laugh;
	sfSoundBuffer	*soundbuffer_laugh;
	sfClock	*c;
	sfClock	*settings;
	sfClock	*settings4;
	sfClock	*settings3;
	sfClock	*settings2;
	sfClock	*player;
	sfClock	*flower;
	sfClock	*tc;
	sfClock	*c2;
	sfClock	*f;
	sfClock	*g;
	mouse_t	*click;
	sfVector2f	p_map;
	sfVector2i	pos;
	sfIntRect	rect;
	char	**map;
	sfView	*view;
	player_e	p;
	quest_e	quest;
	int	i;
	int	in;
	stats_t	*stats;
	int	fire;
	int	fflower;
	enemy_t	*enemy;
	keys_t	*keys;
	anim_t	*anim;
	partBuffer	*this;
	char	**str;
} param_t;

void	gamewin_state(param_t *param);
void	exit_quest(param_t *p);
void	banon_quest(param_t *param);
void	init_sound1(param_t *param);
void	check_flower(param_t *param);
char	*my_strndup(char *line, int n);
char	*score_to_string(int score);
void	display_time_score(param_t *param, sfVector2f tmp);
void	display_time(param_t *param, char *str, sfVector2f tmp);
#include <buttons.h>
# include <particles.h>
void	manage_quest(param_t *g);
void	display_text(param_t *param, char *str, int x, int y);
void	display(param_t *param, char *str, sfVector2f pos, int size);
char	**get_map(char *str);
void	events_manager(param_t *param, sfEvent event);
param_t	*initiate_params(void);
sfIntRect	*configure_rect(int left, int top, int width, int height);
void	initiate_assets(param_t *param);
assets_t	*configure_assets(param_t *param);
assets_t	*initiate_assets_struct(void);
void	*my_malloc(unsigned int size);
void	display_button(param_t *param, char *str, int x);
void	mouse_click_event(param_t *param, sfEvent event);
void	mouse_move_event(param_t *param, sfEvent event);
void	my_title_rect(param_t *param, int anim);
void	my_title_anim(param_t *param);
void	my_title_rect2(param_t *param, int anim);
void	my_title_anim2(param_t *param);
void	sprite_pos(param_t *param);
void	game_score(param_t *param);
sfVector2i	locate_player(param_t *p);
void	draw_player(param_t *p);
void	draw_map(param_t *p);
void	move_player(param_t *g);
void	update_game(param_t *g);
void	simple_rect(param_t *g, int anim);
void	title_rect2(param_t *g, int anim);
void	title_rect2_2(param_t *g, int anim);
void	title_rect2_1(param_t *g, int anim);
void	title_rect2_3(param_t *g, int anim);
void	title_anim(param_t *g, param_t *);
void	my_title_settings(param_t *param, int anim);
void	my_title_anim_settings(param_t *param);
void	my_title_settings2(param_t *param, int anim);
void	my_title_anim_settings2(param_t *param);
void	my_title_settings3(param_t *param, int anim);
void	my_title_anim_settings3(param_t *param);
void	my_title_settings4(param_t *param, int anim);
void	my_title_anim_settings4(param_t *param);
void	sprite_pos_settings(param_t *param);
void	set_play_settings(param_t *param);
void	move_settings(param_t *param);
void	display_text(param_t *param, char *str, int x, int y);
void	draw_settings(param_t *p);
void	display_charachter(param_t *p);
//animations
void	enemy_rect(param_t *g, int anim);
void	enemy_anim(param_t *g, param_t *);
void	attack_rect(param_t *g, int anim);
void	attack_anim(param_t *g);
void	draw_menu(param_t *param);
void	move(param_t *param);
void	set_play(param_t *param);
void	game_pause(param_t *param);
void	my_close_ev(param_t *param);
void	fire_anim(param_t *g);
void	draw_fire(param_t *g, int anim);
void	sprite_pos_intro(param_t *param);
void	set_play_intro(param_t *param);
void	move_intro(param_t *param);
void	skip(param_t *param, char *str, int x, sfColor color);
void	draw_intro(param_t *p);
char	*my_strdup(char *line);
int	my_strcmp(char const *s1, char const *s2);
int	my_strlen(char const *str);
void	my_bzero(char *buffer, int size);
void	game_how(param_t *param);
void	chicken_quest(param_t *p);
void	player_attacks(param_t *param);
void	destroy_sound(param_t *param);
char	**get_key(char *str);
void	game_loader(param_t *param, int *n);
void	player_moving_animation(param_t *param);
void	all_the_animations(param_t *param);
int	my_rpg(param_t *param);
int	my_getnbr(char const *str);
void	init_click(param_t *param);
void	init_anim(param_t *param);
void	init_keys(param_t *param);
void	set_default_values(param_t *param);
void	init_sound(param_t *param);
void	control_flower(param_t *g);
void	get_to_game(param_t *p, int *b, int *k);
void	is_finished(param_t *param);
void	gameend_state(param_t *param);
void	gamedream_state(param_t *p);
void	save_score(param_t *p);
int	check_finalbosmove(param_t *g, int y, int x);
void	move_finalbos(param_t *g);
void	draw_final_boss(param_t *p);
void	bos_rect(param_t *g, int anim);
void	bos_anim(param_t *g, param_t *param);
void	finalbos_state(param_t *p);
char	*read_file(char *str);
void	draw_map_case(param_t *p, char c);
void	copy_map(char *str[], param_t *param);
void	my_free(param_t *param);
#endif // RPG
