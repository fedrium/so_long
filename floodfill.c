/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:40:54 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/27 16:12:50 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	*ft_strdup_w(char *str)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	i = -1;
	while (++i < ft_strlen(str))
	{
		res[i] = str[i];
	}
	res[i] = 0;
	return (res);
}

int	floodfill_helper(char **array, int x, int y, t_count *count)
{
	int	down;
	int	left;
	int	right;
	int	up;

	if (count->exit == 0 && count->coll == 0)
		return (0);
	if (array[x][y] == '1')
		return (1);
	if (array[x][y] == 'C')
		count->coll--;
	if (array[x][y] == 'E')
		count->exit--;
	array[x][y] = '1';
	down = floodfill_helper(array, x, y + 1, count);
	left = floodfill_helper(array, x - 1, y, count);
	right = floodfill_helper(array, x + 1, y, count);
	up = floodfill_helper(array, x, y - 1, count);
	array[x][y] = '0';
	return (right && up && down && left);
}

int	floodfill(char **array, t_count *count, t_info *info)
{
	int		i;
	int		a;
	char	**visited;

	i = 0;
	visited = malloc(sizeof (char **) * (info->game->width + 1));
	while (i <= info->game->width)
	{
		visited[i] = ft_strdup_w(array[i]);
		i++;
	}
	a = floodfill_helper(visited, info->game->tx, info->game->ty, count);
	i = 0;
	while (i <= info->game->width)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (a);
}

void	get_pos(char **array, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= info->game->width)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == 'P')
			{
				info->game->ty = j;
				info->game->tx = i;
				info->plx = j;
				info->ply = i;
			}
			j++;
		}
		i++;
	}
}

void	get_extra_pos(char **array, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= game->width)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == 'P')
			{
				game->coords.cx = i;
				game->coords.cy = j;
			}
			if (array[i][j] == 'E')
			{
				game->coords.ex = i;
				game->coords.ey = j;
			}
			j++;
		}
		i++;
	}
}

// 286451379