/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:50:49 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/30 14:58:19 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_up(t_info *info)
{
	if (info->game->map[info->ply + 1][info->plx] == 'E')
	{
		if (info->coll == 0)
		{
			write(1, "You Win!\n", 10);
			exit(0);
		}
	}
	if (info->game->map[info->ply + 1][info->plx] == '1')
		return (0);
	else
	{
		info->ply = info->ply + 1;
		event(info);
	}
	return (0);
}

int	movement_down(t_info *info)
{
	if (info->game->map[info->ply - 1][info->plx] == 'E')
	{
		if (info->coll == 0)
		{
			write(1, "You Win!\n", 10);
			exit(0);
		}
	}
	if (info->game->map[info->ply - 1][info->plx] == '1')
		return (0);
	else
	{
		info->ply = info->ply - 1;
		event(info);
	}
	return (0);
}

int	movement_right(t_info *info)
{
	if (info->game->map[info->ply][info->plx + 1] == 'E')
	{
		if (info->coll == 0)
		{
			write(1, "You Win!\n", 10);
			exit(0);
		}
	}
	if (info->game->map[info->ply][info->plx + 1] == '1')
		return (0);
	else
	{
		info->plx = info->plx + 1;
		event(info);
	}
	return (0);
}

int	movement_left(t_info *info)
{
	if (info->game->map[info->ply][info->plx - 1] == 'E')
	{
		if (info->coll == 0)
		{
			write(1, "You Win!\n", 10);
			exit(0);
		}
	}
	if (info->game->map[info->ply][info->plx - 1] == '1')
		return (0);
	else
	{
		info->plx = info->plx - 1;
		event(info);
	}
	return (0);
}

int	direction(int keycode, t_info *info)
{
	int	i;

	i = 0;
	if (keycode == 13)
		movement_down(info);
	if (keycode == 1)
		movement_up(info);
	if (keycode == 0)
		movement_left(info);
	if (keycode == 2)
		movement_right(info);
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
	{
		info->movement = info->movement + 1;
		ft_putnbr_fd(info->movement);
		ft_putchar_fd('\n');
	}
	return (0);
}
