/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 02:20:58 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/10 03:57:27 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifndef LINUX
#  define LINUX 1
# endif

/*****************************************/
/*                 Events                */
/*****************************************/
#if LINUX == 0

# define ESC_KEY				65307
# define W_KEY					119
# define A_KEY					97
# define S_KEY					115
# define D_KEY					100
# define UP_KEY					65362
# define LEFT_KEY				65361
# define DOWN_KEY				65364
# define RIGHT_KEY				65363
# define SPACE_KEY				32
#else

# define ESC_KEY				65307
# define W_KEY					119
# define A_KEY					97
# define S_KEY					115
# define D_KEY					100
# define UP_KEY					65362
# define LEFT_KEY				65361
# define DOWN_KEY				65364
# define RIGHT_KEY				65363
# define SPACE_KEY				32

#endif

#endif
