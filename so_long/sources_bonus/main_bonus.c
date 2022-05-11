/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:03:58 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 05:55:36 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	config_list2(t_list *list)
{
	list->images.door_01 = NULL;
	list->images.door_02 = NULL;
	list->images.plant_01 = NULL;
	list->images.plant_02 = NULL;
	list->images.player_01 = NULL;
	list->images.player_02 = NULL;
	list->images.wall_01 = NULL;
	list->images.enemy_01 = NULL;
	list->images.enemy_02 = NULL;
	list->images.enemy_03 = NULL;
	list->images.enemy_04 = NULL;
}

void	config_list(t_list *list)
{
	list->map.map = NULL;
	list->map.map_splitted = NULL;
	list->map.height = 0;
	list->map.width = 0;
	list->map.collectibles = 0;
	list->map.map_exit = 0;
	list->map.players = 0;
	list->mlx.mlx_ptr = NULL;
	list->mlx.win_ptr = NULL;
	list->mlx.height = 0;
	list->mlx.width = 0;
	list->tilemap = NULL;
	list->key_pressed = 0;
	list->steps = 0;
	list->current_player_x = 0;
	list->current_player_y = 0;
}

void	check_args(int argc, char **argv)
{
	int	arg_len;

	if (argc != 2)
		exit_error("Wrong number of arguments\n", NULL);
	if (*argv[1] == 0)
		exit_error("NULL map argument\n", NULL);
	arg_len = ft_strlen(argv[1]);
	if (arg_len <= 4)
		exit_error("Map argument invalid\n", NULL);
	if (argv[1][arg_len - 1] != 'r'
		|| argv[1][arg_len - 2] != 'e'
		|| argv[1][arg_len - 3] != 'b'
		|| argv[1][arg_len - 4] != '.')
	{
		exit_error("Wrong map extension\n", NULL);
	}
	if (argv[1][arg_len - 5] == '/')
	{
		exit_error("No map name\n", NULL);
	}
}

int	main(int argc, char **argv)
{
	t_list	list;

	srand(time(NULL));
	config_list(&list);
	config_list2(&list);
	check_args(argc, argv);
	map_treatment(&list, argv[1]);
	tilemap_treatment(&list);
	if (DEBUG == 1)
		debug(&list);
	config_game(&list);
	free_list(&list);
	return (0);
}
