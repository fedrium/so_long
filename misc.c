/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:00:24 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/27 16:23:07 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-');
		ft_putchar_fd('2');
		ft_putnbr_fd(147483648);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-');
		ft_putnbr_fd(-n);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
	else
		ft_putchar_fd(n + '0');
}

int	word_check_helper(char **array, t_info *info, t_count *count)
{
	int	i;
	int	j;

	i = 0;
	count->coll = 0;
	count->exit = 0;
	info->coll = 0;
	while (i < info->game->width)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == 'C')
			{
				count->coll++;
				info->coll++;
			}
			if (array[i][j] == 'E')
				count->exit++;
			j++;
		}
		i++;
	}
	return (0);
}

int	filecheck(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
	{
		write(1, "Error!\n", 7);
		return (1);
	}
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (0);
	write(1, "Error!\n", 7);
	return (1);
}

int	fdcheck(int fd)
{
	if (fd < 1)
	{
		write(1, "Error!\n", 7);
		return (1);
	}
	return (0);
}
