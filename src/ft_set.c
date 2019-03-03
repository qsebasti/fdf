/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:56:06 by qsebasti          #+#    #+#             */
/*   Updated: 2018/01/23 21:48:10 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			ft_set(t_env *e)
{
	e->str = NULL;
	e->lines = 0;
	e->x = 0;
	e->y = 0;
	e->w = WIDTH / 3;
	e->h = HEIGHT / 3;
	e->pix = PIX;
	e->gap = 0.2;
	e->rotx = 0;
	e->roty = 0;
	e->rotz = 0;
	e->zr = 0;
	ft_bzero(e->key, 300);
	e->min = 2147483647;
	e->max = -2147483648;
}

static int		tablen(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		create_point(t_env *e, char **buf, int x)
{
	int		i;

	i = 0;
	if (!(e->pt[x] = (t_point *)malloc(sizeof(t_point) * (tablen(buf) + 1))))
		return (fdf_error(4));
	while (buf[i])
	{
		if (!(ft_isdigit(buf[i][0])) && buf[i][0] != '-')
			return (fdf_error(5));
		e->pt[x][i].x = i;
		e->pt[x][i].y = x;
		e->pt[x][i].z = ft_atoi(buf[i]);
		e->pt[x][i].x2d = (((e->pt[x][i].x * CTE1) - (CTE2 * e->pt[x][i].y)) *
				e->pix) + e->w;
		e->pt[x][i].y2d = (((e->pt[x][i].y * CTE3) + (e->pt[x][i].x * CTE4) -
					e->pt[x][i].z * e->gap) * e->pix) + e->h;
		e->max = (e->pt[x][i].z > e->max ? e->pt[x][i].z : e->max);
		e->min = (e->pt[x][i].z < e->min ? e->pt[x][i].z : e->min);
		i++;
	}
	e->pt[x][i].x = -1;
	ft_freesplit(buf);
	return (1);
}

static int		ft_nblines(char *av)
{
	int		fd;
	char	*tmp;
	int		ret;
	int		lines;

	lines = 0;
	tmp = NULL;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &tmp)) > 0)
	{
		lines++;
		free(tmp);
	}
	if ((close(fd)) < 0)
		return (-1);
	return (lines);
}

int				start(char *av, t_env *e)
{
	char	*buf;
	int		ret;
	int		fd;
	int		x;

	x = 0;
	buf = NULL;
	if (((e->lines = ft_nblines(av)) == -1) ||
			((fd = open(av, O_RDONLY)) < 0))
		return (fdf_error(3));
	if (!(e->pt = (t_point **)malloc(sizeof(t_point *) * (e->lines + 1))))
		return (fdf_error(4));
	if ((fd = open(av, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &buf)) > 0)
	{
		if (ret == -1)
			return (fdf_error(3));
		if ((create_point(e, ft_strsplit(buf, ' '), x)) < 1)
			return (0);
		free(buf);
		x++;
	}
	return (1);
}
