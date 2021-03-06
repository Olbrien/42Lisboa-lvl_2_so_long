/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:58:01 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 05:46:37 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_list *list)
{
	if (list->images.door_01 != NULL)
		mlx_destroy_image(list->mlx.mlx_ptr, list->images.door_01);
	if (list->images.door_02 != NULL)
		mlx_destroy_image(list->mlx.mlx_ptr, list->images.door_02);
	if (list->images.plant_01 != NULL)
		mlx_destroy_image(list->mlx.mlx_ptr, list->images.plant_01);
	if (list->images.plant_02 != NULL)
		mlx_destroy_image(list->mlx.mlx_ptr, list->images.plant_02);
	if (list->images.player_01 != NULL)
		mlx_destroy_image(list->mlx.mlx_ptr, list->images.player_01);
	if (list->images.player_02 != NULL)
		mlx_destroy_image(list->mlx.mlx_ptr, list->images.player_02);
	if (list->images.wall_01 != NULL)
		mlx_destroy_image(list->mlx.mlx_ptr, list->images.wall_01);
	if (list->mlx.win_ptr != NULL)
		mlx_destroy_window(list->mlx.mlx_ptr, list->mlx.win_ptr);
}

void	free_list(t_list *list)
{
	int	i;

	i = 0;
	if (list->map.map != NULL)
	{
		free(list->map.map);
		list->map.map = NULL;
	}
	if (list->map.map_splitted != NULL)
	{
		while (list->map.map_splitted[i] != NULL)
			free(list->map.map_splitted[i++]);
		free(list->map.map_splitted);
	}
	i = 0;
	if (list->tilemap != NULL)
	{
		while (i < list->map.height)
			free(list->tilemap[i++]);
		free(list->tilemap);
	}
}

void	exit_error(char *str, t_list *list)
{
	int	len;

	if (list != NULL)
	{
		free_list(list);
		free_mlx(list);
	}
	len = ft_strlen(str);
	write(2, "Error\n", 6);
	write(2, str, len);
	exit(1);
}

int	exit_no_error(t_list *list)
{
	if (list != NULL)
	{
		free_list(list);
		free_mlx(list);
	}
	exit(0);
}

void	debug(t_list *list)
{
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (list->map.map_splitted[i] != NULL)
	{
		write(1, list->map.map_splitted[i], \
				ft_strlen(list->map.map_splitted[i]));
		write(1, "\n", 1);
		i++;
	}
	write(1, "\nHeight: ", 9);
	ft_putnbr_fd(list->map.height, 1);
	write(1, "\nWidth: ", 8);
	ft_putnbr_fd(list->map.width, 1);
	write(1, "\nCollectibles: ", 15);
	ft_putnbr_fd(list->map.collectibles, 1);
	write(1, "\nStarting positions: ", 21);
	ft_putnbr_fd(list->map.players, 1);
	write(1, "\nExits: ", 8);
	ft_putnbr_fd(list->map.map_exit, 1);
	write(1, "\n", 1);
}
