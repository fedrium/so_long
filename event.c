/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:17:28 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/27 16:40:45 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	event(t_info *info)
{
	if (info->game->map[info->ply][info->plx] == 'C')
	{
		info->coll = info->coll - 1;
		info->game->map[info->ply][info->plx] = '0';
	}
	return (0);
}
