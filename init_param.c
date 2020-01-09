/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

# include <rpg.h>

assets_t	*initiate_assets_struct(void)
{
	assets_t	*ass = my_malloc(sizeof(assets_t) * ASSETS_CNT);

	ass->texture = NULL;
	ass->sprite = NULL;
	return (ass);
}

static void	configure_assets1(assets_t *ass)
{
	ass[0].texture = sfTexture_createFromFile("./assets/play.png", NULL);
	ass[1].texture = sfTexture_createFromFile("./assets/play.png", NULL);
	ass[2].texture = sfTexture_createFromFile("./assets/fifi.png", NULL);
	ass[3].texture = sfTexture_createFromFile("./assets/fifi2.png", NULL);
	ass[4].texture = sfTexture_createFromFile("./assets/bos.png", NULL);
	ass[5].texture = sfTexture_createFromFile("./assets/score.png", NULL);
	ass[6].texture = sfTexture_createFromFile("./assets/pause.png", NULL);
	ass[7].texture = sfTexture_createFromFile("./assets/front.png", NULL);
	ass[8].texture = sfTexture_createFromFile("./assets/sky2.png", NULL);
	ass[9].texture = sfTexture_createFromFile("./assets/sky2.png", NULL);
	ass[21].texture = sfTexture_createFromFile("./assets/sky2.png", NULL);
	ass[22].texture = sfTexture_createFromFile("./assets/sky2.png", NULL);
	ass[10].texture = sfTexture_createFromFile("./assets/skill.png", NULL);
	ass[28].texture = sfTexture_createFromFile("./assets/enemy1.png", NULL);
	ass[29].texture = sfTexture_createFromFile("./assets/fire.png", NULL);
	ass[30].texture = sfTexture_createFromFile("./assets/f.png", NULL);
	ass[31].texture = sfTexture_createFromFile("./assets/dream.png", NULL);
}

static void	configure_assets2(assets_t *ass)
{
	ass[11].texture = sfTexture_createFromFile("./assets/flaka.png", NULL);
	ass[12].texture = sfTexture_createFromFile("./assets/player1.1.png",
	NULL);
	ass[13].texture = sfTexture_createFromFile("./assets/p2.png", NULL);
	ass[14].texture = sfTexture_createFromFile("./assets/p4.png", NULL);
	ass[15].texture = sfTexture_createFromFile("./assets/nona1.png", NULL);
	ass[16].texture = sfTexture_createFromFile("./assets/nona2.png", NULL);
	ass[17].texture = sfTexture_createFromFile("./assets/nona3.png", NULL);
	ass[18].texture = sfTexture_createFromFile("./assets/Untitled.png",
	NULL);
	ass[19].texture = sfTexture_createFromFile("./assets/car.png", NULL);
	ass[20].texture = sfTexture_createFromFile("./assets/luft1.png", NULL);
	ass[23].texture = sfTexture_createFromFile("./assets/luft2.png", NULL);
	ass[24].texture = sfTexture_createFromFile("./assets/luft3.png", NULL);
	ass[25].texture = sfTexture_createFromFile("./assets/white.png", NULL);
	ass[26].texture = sfTexture_createFromFile("./assets/puzzle.png", NULL);
	ass[27].texture = sfTexture_createFromFile("./assets/inventory.png",
	NULL);
}

assets_t	*configure_assets(param_t *param)
{
	assets_t	*ass = param->assets;
	configure_assets1(ass);
	configure_assets2(ass);
	param->default_font = sfFont_createFromFile("./assets/default.otf");
	return (ass);
}

void	initiate_assets(param_t *param)
{
	assets_t	*ass = configure_assets(param);

	for (int i = 0; i < ASSETS_CNT; i++) {
		ass[i].sprite = sfSprite_create();
		sfSprite_setTexture(ass[i].sprite, ass[i].texture, sfTrue);
	}
	param->assets = ass;
}
