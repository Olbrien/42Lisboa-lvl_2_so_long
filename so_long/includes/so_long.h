/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:58:14 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 04:07:49 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "events.h"
# include "masks.h"
# include "keys.h"

# ifndef DEBUG
#  define DEBUG 1
# endif


/*****************************************/
/*                Macros                 */
/*****************************************/
# define IMG_SIZE 64

# define EMPTY_SPACE 1
# define WALL 2
# define COLLECTIBLE 3
# define MAP_EXIT 4
# define PLAYER_POSITION 5

/*****************************************/
/*                 Data                  */
/*****************************************/
typedef struct s_tilemap
{
	int		type;
	int		original_type;

	int		width;
	int		height;

	struct s_tilemap *up;
	struct s_tilemap *down;
	struct s_tilemap *left;
	struct s_tilemap *right;

} t_tilemap;

typedef struct s_map
{
	char	*map;
	char	**map_splitted;
	int		height;
	int		width;
	int		collectibles;
	int		map_exit;
	int		players;

} t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;

} t_mlx;

/********/
/* Color */
/********/
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;

} t_color;

/********************/
/* Full Screen Panel */
/********************/
typedef struct s_panel
{
	char		*pixels;
	int			bpp;
	int			line_size;
	int			endian;
	int			x;
	int			y;

} t_panel;

typedef struct s_effects
{
	void	*img_white_flash_ptr;
	void	*img_red_flash_ptr;
	void	*img_pink_flash_ptr;

} t_effects;

/**********/
/* General */
/**********/
typedef struct s_list
{
	struct s_map		map;
	struct s_mlx		mlx;
	struct s_effects	effects;
	struct s_tilemap	**tilemap;

}	t_list;

/*****************************************/
/*                Utility                */
/*****************************************/
void	exit_error(char *str, t_list *list);
int		exit_no_error(t_list *list);
void	free_list(t_list *list);
void	debug(t_list *list);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

/*****************************************/
/*                  Map                  */
/*****************************************/
void	tilemap_treatment(t_list *list);

void	map_treatment(t_list *list, char *map_file);

void	check_if_map_is_rectangular(t_list *list);
void	check_if_map_is_closed(t_list *list);
void	check_map_components(t_list *list);

/*****************************************/
/*                  mlx                  */
/*****************************************/
void	config_game(t_list *list);

/*****************************************/
/*                 Panel                 */
/*****************************************/
void	create_panel(t_list *list, void **img_ptr, t_color color);
t_color	create_color(int r, int g, int b, int a);

/*****************************************/
/*                  Loop                 */
/*****************************************/
int key_press(int keycode, t_list *list);


#endif
