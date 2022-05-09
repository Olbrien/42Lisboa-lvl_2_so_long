/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:58:14 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/09 02:55:22 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef DEBUG
#  define DEBUG 1
# endif

/*********************/
/*        Data       */
/*********************/
typedef struct s_map
{
	char	*map;
	char	**map_splitted;
	int		height;
	int		width;
	int		surrounded_by_walls;
	int		collectibles;
	int		map_exit;
	int		players;

}	t_map;

typedef struct s_list
{
	struct s_map	map;

}	t_list;

/*********************/
/*      Utility      */
/*********************/
void	exit_error(char *str, t_list *list);
void	free_list(t_list *list);
void	debug(t_list *list);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

/*********************/
/*        Map        */
/*********************/
void	map_treatment(t_list *list, char *map_file);

void	check_if_map_is_rectangular(t_list *list);
void	check_if_map_is_closed(t_list *list);

#endif
