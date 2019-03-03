/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:07:43 by qsebasti          #+#    #+#             */
/*   Updated: 2018/01/23 21:47:17 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				getcolor(t_point *p1, t_point *p2, t_env *e, float k)
{
	t_color c;
	int		i;
	int		diff;

	i = -1;
	diff = e->max - e->min;
	if (p1->z >= e->max - diff * 0.2)
		p1->color.color = SNOW;
	if (p1->z < e->max - diff * 0.2 && p1->z >= e->max - diff * 0.7)
		p1->color.color = MOUNTAIN;
	if (p1->z < e->max - diff * 0.7 && p1->z > 0)
		p1->color.color = LAND;
	if (p1->z <= 0)
		p1->color.color = WATER;
	if (p2->z >= e->max - diff * 0.2)
		p2->color.color = SNOW;
	if (p2->z < e->max - diff * 0.2 && p2->z >= e->max - diff * 0.7)
		p2->color.color = MOUNTAIN;
	if (p2->z < e->max - diff * 0.7 && p2->z > 0)
		p2->color.color = LAND;
	if (p2->z <= 0)
		p2->color.color = WATER;
	while (++i < 4)
		c.rgb[i] = p1->color.rgb[i] + (p2->color.rgb[i] - p1->color.rgb[i]) * k;
	return (c.color);
}

int				keyrelease(int keycode, t_env *e)
{
	e->key[keycode] = 0;
	return (1);
}

int				keypress(int keycode, t_env *e)
{
	e->key[keycode] = 1;
	return (1);
}

static void		info(char **s)
{
	s[0] = "Display commands :";
	s[1] = "Move : key UP/DOWN/LEFT/RIGHT";
	s[2] = "Zoom in/out : key +/-";
	s[3] = "High more/less : key 1/2";
	s[4] = "Rotation axis x, y, z : key 4/7, 5/8, 6/9";
	s[5] = "Reset : backspace";
	s[6] = NULL;
}

int				exposehook(t_env *e)
{
	char	*s[7];
	int		i;
	int		j;

	j = 5;
	i = 0;
	info(s);
	if (!(e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT)))
		return (fdf_error(5));
	mlx_clear_window(e->mlx, e->win);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_len), &(e->end));
	keyhook(e);
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 500, 5, 0xFFFFFF, e->str);
	while (s[i])
	{
		mlx_string_put(e->mlx, e->win, 5, j, 0xFFFFFF, s[i]);
		j += 22;
		i++;
	}
	mlx_destroy_image(e->mlx, e->img);
	return (1);
}
