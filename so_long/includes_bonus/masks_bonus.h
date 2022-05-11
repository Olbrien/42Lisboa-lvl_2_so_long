/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:23:15 by tisantos          #+#    #+#             */
/*   Updated: 2022/05/11 02:34:30 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASKS_BONUS_H
# define MASKS_BONUS_H

# ifndef LINUX
#  define LINUX 1
# endif

/*****************************************/
/*                 Masks                 */
/*****************************************/
# define NOEVENTMASK				0
# define KEYPRESSMASK				1
# define KEYRELEASEMASK				2
# define BUTTONPRESSMASK			3
# define BUTTONRELEASEMASK			4
# define ENTERWINDOWMASK			5
# define LEAVEWINDOWMASK			6
# define POINTERMOTIONMASK			7
# define POINTERMOTIONHINTMASK		8
# define BUTTON1MOTIONMASK			9
# define BUTTON2MOTIONMASK			10
# define BUTTON3MOTIONMASK			11
# define BUTTON4MOTIONMASK			12
# define BUTTON5MOTIONMASK			13
# define BUTTONMOTIONMASK			14
# define KEYMAPSTATEMASK			15
# define EXPOSUREMASK				16
# define VISIBILITYCHANGEMASK		17
# define STRUCTURENOTIFYMASK		18
# define RESIZEREDIRECTMASK			19
# define SUBSTRUCTURENOTIFYMASK		20
# define SUBSTRUCTUREREDIRECTMASK	21
# define FOCUSCHANGEMASK			22
# define PROPERTYCHANGEMASK			23
# define COLORMAPCHANGEMASK			24
# define OWNERGRABBUTTONMASK		25

#endif
