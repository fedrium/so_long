/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:51:19 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/27 15:54:23 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	cleanexit(void)
{
	exit(0);
}

void	image(t_info info)
{	
	info.player = "./player.xpm";
	info.mlx.mlx = mlx_init();
	info.mlx.mlx_win = mlx_new_window
		(info.mlx.mlx, info.game->length * 64,
			(info.game->width + 1) * 64, "So_Long");
	map(&info);
	mlx_loop_hook(info.mlx.mlx, loop_hooker, &info);
	mlx_hook(info.mlx.mlx_win, 17, 0, cleanexit, &info);
	mlx_key_hook(info.mlx.mlx_win, direction, &info);
	mlx_loop(info.mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_count	count;
	int		fd;
	int		area;

	(void)argc;
	info.game = malloc(sizeof(t_game));
	info.img = malloc(sizeof(t_img));
	info.img->img_width = 64;
	info.img->img_height = 64;
	info.movement = 0;
	if (filecheck(argv[1]) == 1)
		return (0);
	fd = open(argv[1], 0);
	if (fdcheck(fd) == 1)
		return (0);
	area = map_allocate(fd, &info);
	get_pos(info.game->map, &info);
	if (checker(info.game->map, &info, &count) == 1)
	{
		write(1, "Error!\n", 7);
		return (0);
	}
	image(info);
	return (0);
}

int	player_checker(t_info *info)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (i <= info->game->width)
	{
		j = 0;
		while (info->game->map[i][j] != '\0')
		{
			if (info->game->map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (1);
	return (0);
}
