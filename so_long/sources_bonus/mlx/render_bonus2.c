/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:26:51 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 04:13:00 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_step_text(t_list *list)
{
	char		*str;

	str = ft_itoa(list->steps);
	mlx_string_put(list->mlx.mlx_ptr, list->mlx.win_ptr,
		10, list->mlx.height + 17, 16761035, "steps: ");
	mlx_string_put(list->mlx.mlx_ptr, list->mlx.win_ptr,
		50, list->mlx.height + 17, 16761035, str);
	free (str);
}

void	render_exit(t_list *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->map.height)
	{
		x = 0;
		while (x < list->map.width)
		{
			if (list->tilemap[y][x].type == MAP_EXIT)
			{
				list->tilemap[y][x].image = list->images.door_02;
			}
			x++;
		}
		y++;
	}
	list->map.collectibles = -1;
}
