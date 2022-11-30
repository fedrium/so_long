/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:57 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/28 17:48:11 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map(t_info *info)
{
	info->img->coll = mlx_xpm_file_to_image(info->mlx.mlx, "collectible.xpm",
			&info->img->img_width, &info->img->img_height);
	info->img->wall = mlx_xpm_file_to_image(info->mlx.mlx, "wall.xpm",
			&info->img->img_width, &info->img->img_height);
	info->img->ground = mlx_xpm_file_to_image(info->mlx.mlx, "grass.xpm",
			&info->img->img_width, &info->img->img_height);
	info->img->exit = mlx_xpm_file_to_image(info->mlx.mlx, "exit.xpm",
			&info->img->img_width, &info->img->img_height);
	return (0);
}

int	map_loop(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i <= info->game->width)
	{
		j = 0;
		while (info->game->map[i][j] != '\0')
		{
			if (info->game->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx.mlx,
					info->mlx.mlx_win, info->img->wall, j * 64, i * 64);
			if (info->game->map[i][j] == '0' || info->game->map[i][j] == 'P')
				mlx_put_image_to_window(info->mlx.mlx,
					info->mlx.mlx_win, info->img->ground, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_loop_helper(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i <= info->game->width)
	{
		j = 0;
		while (info->game->map[i][j] != '\0')
		{
			if (info->game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(info->mlx.mlx,
					info->mlx.mlx_win, info->img->ground, j * 64, i * 64);
				mlx_put_image_to_window(info->mlx.mlx,
					info->mlx.mlx_win, info->img->coll, j * 64, i * 64);
			}
			if (info->game->map[i][j] == 'E')
				mlx_put_image_to_window(info->mlx.mlx,
					info->mlx.mlx_win, info->img->exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

int	put_img(t_info *info)
{
	t_img	img;

	img.player = mlx_xpm_file_to_image(info->mlx.mlx, "./player.xpm",
			&img.img_width, &img.img_height);
	img.ground = mlx_xpm_file_to_image(info->mlx.mlx, "./grass.xpm",
			&img.img_width, &img.img_height);
	mlx_put_image_to_window(info->mlx.mlx, info->mlx.mlx_win,
		img.ground, info->plx * 64, info->ply * 64);
	mlx_destroy_image(info->mlx.mlx, img.ground);
	mlx_put_image_to_window(info->mlx.mlx, info->mlx.mlx_win,
		img.player, info->plx * 64, info->ply * 64);
	mlx_destroy_image(info->mlx.mlx, img.player);
	return (0);
}

int	loop_hooker(t_info *info)
{
	map_loop(info);
	map_loop_helper(info);
	put_img(info);
	return (0);
}
