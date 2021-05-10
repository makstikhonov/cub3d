/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:23:48 by max               #+#    #+#             */
/*   Updated: 2021/05/01 21:37:47 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define	RAYCAST_H
# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_sprite
{
	double			x;
	double			y;
	double			dist;
	struct s_sprite	*next;
}				t_sprite;

typedef struct s_sp
{
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		vMoveScreen;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
}				t_sp;

typedef struct s_wl
{
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		side;
	double	cameraX;
	int		stepX;
	int		stepY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;
	int		texX;
	int		texY;
}				t_wl;

typedef struct s_info
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	void		*mlx;
	void		*win;
	int			key;
	t_sprite	**sprt;
	int			**buf;
	double		*zBuffer;
	int			**texture;
	double		moveSpeed;
	int			w_width;
	int			w_height;
	double		rotSpeed;
	char		**path;
	int			floor_color;
	int			ceiling_color;
	char		**worldmap;
	char		**tempmap;
	int			num_sprts;
	int			texWidth;
	int			texHeight;
	int			save;
	int			end;
	int			r;
	int			g;
	int			b;
}				t_info;

int				key_pressed(int key, t_info *info);
int				read_map (t_info *info, int fd);
char			**make_map(t_list **head, int size);
int				check_map_file_name(char *filename);
int				file_exists(char *file_name);
int				is_space(char c);
int				ft_parse_file(t_info *info, char *filename);
void			parse_line(char **line, t_info *info, t_list **head, int i);
int				is_type(t_info *info, char a, char b, char *line);
int				extract_resolution(char *line, t_info *info);
int				extract_path(t_info *info, int index, char *line);
int				get_next_line(int fd, char **line);
int				is_map_character(char c);
void			extract_color(t_info *info, char location, char *line);
unsigned long	createRGB(int r, int g, int b);
int				ft_init_map(t_info *info);
t_sprite		**ft_init_sprites(t_info *info);
void			ft_sprites_distance_sort(t_sprite **sprites, int length);
void			ft_bmp(t_info *info, t_img *image);
int				main_loop(t_info *info);
int				load_texture(t_info *info);
void			ft_init(t_info *info);
int				ft_load_texture(t_info *info);
void			draw(t_info *info, t_img *image);
void			calc(t_info *info);
void			ft_init2(t_info *info);
void			ft_errors(char error, t_info *info, int free);
void			ft_errors2(char error);
void			ft_init3(int save, char *filename);
int				quit(t_info *info);
int				ft_count_sprites(t_info *info);
void			ft_free_tempmap(t_info *info);
void			ft_check_map_is_enclosed(t_info *info, int x, int y);
void			ft_free(t_info *info);
void			calc_sprite(t_info *info);
void			calc(t_info *info);
void			calc_floor(t_info *info);
void			calc_wall(t_info *info);
void			calc_wall_dda(t_info *info, t_wl *wl);
void			ft_lst_clear(t_list *list);
int				check_map_file_name(char *filename);
int				ft_parse_file(t_info *info, char *filename);
int				ft_check_parse(t_info *info);
#endif