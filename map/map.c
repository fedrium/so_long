/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:11:45 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/30 14:39:23 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*j;

	i = 0;
	j = s;
	while (n > i)
	{
		j[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;

	dst = (char *)malloc (count * size);
	if (dst == NULL)
		return (NULL);
	if (count > 4294967295 || size > 4294967295)
		return (NULL);
	ft_bzero(dst, (count * size));
	return (dst);
}

void	size_cal(char *string, t_info *info)
{
	int	j;
	int	i;

	i = 0;
	while (string[i] != '\n')
		i++;
	info->game->length = i;
	j = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			j++;
		i++;
	}
	info->game->width = j;
}

int	map_allocate(int fd, t_info *info)
{
	int		area;
	char	*string;
	int		i;

	i = 0;
	string = ft_calloc(sizeof(char), 9000);
	area = read(fd, string, 9000);
	if (area == 0)
	{
		write(1, "Error! File is empty\n", 21);
		return (1);
	}
	size_cal(string, info);
	info->game->map = ft_split(string, '\n');
	while (i <= info->game->width)
	{
		if (info->game->map[i] == NULL && i <= info->game->width)
		{
			write(1, "Error! File formatting bad\n", 28);
			exit(1);
		}
		i++;
	}
	free(string);
	return (area);
}
