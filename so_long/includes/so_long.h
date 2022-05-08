/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:58:14 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/08 23:05:58 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*********************/
/*        Data       */
/*********************/
typedef struct s_map
{
	char*	map;

	int		height;
	int		width;

	int		surrounded_by_walls;	/* 0 = no | 1 = yes */
	int		collectibles;			/* number of collectibles */
	int		map_exit;				/* number of map exits */
	int		players;				/* number of players */

} t_map;

typedef struct s_list
{
	struct	s_map  map;

} t_list;

/*********************/
/*      Utility      */
/*********************/
int		ft_strlen(char *str);
void	exit_error(char *str, t_list *list);

/*********************/
/*        Map        */
/*********************/
void	parse_map(t_list *list, char *arg);





#endif
