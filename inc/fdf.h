/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:34:08 by qsebasti          #+#    #+#             */
/*   Updated: 2018/01/24 13:03:27 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <OpenGL/glext.h>
# include <GLUT/glut.h>
# include "../libft/libft.h"
# include <math.h>

# define KEY_ESC 53
# define KEY_ENTER 36
# define KEY_DEL 51
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_0 82
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92
# define KEY_PLUS 69
# define KEY_MINUS 78

# define WIDTH 1275
# define HEIGHT 1300
# define PIX 30
# define CTE1 0.8
# define CTE2 0.8
# define CTE3 0.8 / 2
# define CTE4 0.8 / 2
# define ROT M_PI_2 / 32

# define BLUE 0
# define GREEN 1
# define RED 2
# define ALPHA 3

# define WATER 0x1034a6
# define LAND 0x149414
# define MOUNTAIN 0x5b3c11
# define SNOW 0xffffafa

typedef struct		s_var
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	alpha;
}					t_var;

typedef union		u_color
{
	int				color;
	unsigned char	rgb[4];
	t_var			var;
}					t_color;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	double			x2d;
	double			y2d;
	double			tmpx;
	double			tmpy;
	t_color			color;
}					t_point;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*str;
	t_point			**pt;
	char			*data;
	int				bpp;
	int				s_len;
	int				end;
	int				lines;
	int				x;
	int				y;
	int				w;
	int				h;
	int				pix;
	double			gap;
	double			rotx;
	double			roty;
	double			rotz;
	double			dx;
	double			dy;
	int				xinc;
	int				yinc;
	double			tx;
	double			ty;
	int				zr;
	int				key[300];
	int				min;
	int				max;
}					t_env;

void				ft_set(t_env *e);
int					fdf_error(int a);
int					start(char *av, t_env *e);

int					keyhook(t_env *e);
int					keypress(int keycode, t_env *e);
int					keyrelease(int keycode, t_env *e);
int					exposehook(t_env *e);

void				ft_draw(t_env *e);
void				move(t_env *e);
int					getcolor(t_point *p1, t_point *p2, t_env *e, float k);
#endif
