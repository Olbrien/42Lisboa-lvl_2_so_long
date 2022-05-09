/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:58:07 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/09 04:19:37 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_new_lines_from_map(t_list *list, int i, int line_break)
{
	i = 0;
	line_break = 0;
	if (list->map.map == NULL)
		exit_error("Map is empty\n", list);
	while (list->map.map[i] == '\n')
		i++;
	while (list->map.map[i] != '\0')
	{
		if (list->map.map[i] == '\n')
		{
			if (i > 0 && list->map.map[i - 1] == '\n')
				line_break = 1;
			i++;
			continue ;
		}
		if (line_break == 1 && list->map.map[i] != '\n')
			exit_error("Line Break inside of map\n", list);
		i++;
	}
	if (list->map.map != NULL)
		list->map.map_splitted = ft_split(list->map.map, '\n');
	if (list->map.map_splitted[0] == NULL)
		exit_error("Map is empty\n", list);
}

void	parse_map_to_struct(t_list *list, char *map_file)
{
	int		map_fd;
	char	buffer[2];
	char	*temp;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		exit_error("Map file not found or has an error\n", list);
	while (read(map_fd, &buffer, 1) > 0)
	{
		buffer[1] = '\0';
		if (list->map.map == NULL)
			list->map.map = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(list->map.map, buffer);
			free(list->map.map);
			list->map.map = temp;
		}
	}
	close(map_fd);
}

void	map_treatment(t_list *list, char *map_file)
{
	parse_map_to_struct(list, map_file);
	remove_new_lines_from_map(list, 0, 0);
	check_if_map_is_rectangular(list);
	check_if_map_is_closed(list);
	check_map_components(list);
}
