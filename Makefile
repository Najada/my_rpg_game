##
## EPITECH PROJECT, 2018
## joan
## File description:
## joan
##

SRC	=	play.c	\
		play1.c	\
		init_param.c	\
		my_malloc.c	\
		score.c	\
		events.c	\
		mouse_move_event.c	\
		mouse_click_event.c	\
		manage_score.c	\
		intro.c	\
		settings.c	\
		main.c	\
		menu_anim.c	\
		settings_utils.c	\
		settings_utils1.c	\
		quest.c	\
		utils.c	\
		param.c	\
		param1.c	\
		configure_rect.c	\
		map.c	\
		upate_player.c	\
		buttons.c	\
		buttons1.c	\
		buttons_realised.c	\
		move_buttons.c	\
		move_buttons1.c	\
		draw_map.c	\
		update_game.c	\
		text.c	\
		player_animation.c	\
		how_to_play.c	\
		menu.c	\
		pause.c	\
		fire.c	\
		fight_system.c	\
		game.c	\
		gameplay_utils.c	\
		my_rpg.c	\
		chicken_quest.c	\
		game_state.c	\
		particles.c	\
		banon_quest.c	\
		gamedreame_state.c	\
		dream_button.c	\
		final_bos.c	\
		finalbos_move.c	\
		save_score.c	\
		destroy.c	\

NAME	=	my_rpg

CFLAGS	=	-ggdb -Wall -Wextra -W

LDFLAGS	=	-lc_graph_prog -I ./include

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

c:	fclean clean
