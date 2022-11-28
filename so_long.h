/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:12:06 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/11/27 16:31:33 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_mlx {
	void	*mlx_win;
	void	*mlx;
}				t_mlx;

typedef struct s_img{
	void	*player;
	void	*wall;
	void	*coll;
	void	*ground;
	int		img_width;
	int		img_height;
	void	*exit;
}				t_img;

typedef struct s_coords {
	int	cx;
	int	cy;
	int	ex;
	int	ey;
}				t_coords;

typedef struct s_game {	
	t_coords	coords;
	int			tx;
	int			ty;
	int			width;
	int			length;
	char		**map;
	char		*player;
	char		*col;
	char		*exit;
}				t_game;

typedef struct s_info {
	t_game	*game;
	t_mlx	mlx;
	t_img	*img;
	int		plx;
	int		ply;
	char	*player;
	char	*wall;
	char	*ground;
	int		coll;
	int		movement;
	int		x;
	int		y;
}				t_info;

typedef struct s_count {
	int	coll;
	int	exit;
}				t_count;

char	*get_next_line(int fd);
int		map_allocate(int fd, t_info *info);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *str);
int		checker(char **array, t_info *info, t_count *count);
int		floodfill(char **array, t_count *count, t_info *info);
void	get_pos(char **array, t_info *info);
int		map(t_info *info);
int		map_loop(t_info *info);
int		loop_hooker(t_info *info);
int		player_checker(t_info *info);
int		direction(int keycode, t_info *info);
int		event(t_info *info);
void	ft_putnbr_fd(int n);
void	ft_putchar_fd(char c);
void	xpmtoimg(char *img, t_info *info);
int		word_check_helper(char **array, t_info *info, t_count *count);
int		filecheck(char *str);
int		fdcheck(int fd);

#endif