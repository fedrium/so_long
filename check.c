/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:34:03 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/28 10:51:01 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	word_check(char **array, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->game->width)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] != '1' && array[i][j] != '0' &&
			array[i][j] != 'E' && array[i][j] != 'C' &&
			array[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	size_check(char **array, t_info *info)
{
	int	i;

	i = 1;
	while (i < info->game->width)
	{
		if (ft_strlen(array[0]) != ft_strlen(array[i]))
			return (1);
		i++;
	}
	return (0);
}

int	wall_check(char **array, t_info *info)
{
	int	j;

	j = 0;
	while (j < info->game->length)
	{
		if (array[0][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (j < info->game->length)
	{
		if (array[info->game->width][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	vert_wall(char **array, t_info *info)
{
	int	j;

	j = 0;
	while (j < info->game->width)
	{
		if (array[j][0] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (j < info->game->width)
	{
		if (array[j][info->game->length - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	checker(char **array, t_info *info, t_count *count)
{	
	word_check_helper(array, info, count);
	if (word_check(array, info) == 1 || size_check(array, info) == 1
		|| wall_check(array, info) == 1 || vert_wall(array, info) == 1)
		return (1);
	if (player_checker(info) == 1)
		return (1);
	if (count->coll < 1 || count->exit != 1)
		return (1);
	if (floodfill(array, count, info) == 1)
		return (1);
	return (0);
}
