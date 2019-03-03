/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:37:14 by qsebasti          #+#    #+#             */
/*   Updated: 2018/01/23 17:52:48 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		put_point(t_point *pt, t_env *e, int color)
{
	if (pt->x2d < WIDTH && pt->x2d >= 0 && pt->y2d < HEIGHT && pt->y2d >= 0)
		*(int *)&e->data[(int)pt->x2d * (e->bpp / 8) + (int)pt->y2d *
			e->s_len] = color;
}

static void		line_setup(t_point *p1, t_point *p2, t_point *tmp, t_env *e)
{
	tmp->x2d = p1->x2d;
	tmp->y2d = p1->y2d;
	tmp->color.color = p1->color.color;
	e->dx = p2->x2d - p1->x2d;
	e->dy = p2->y2d - p1->y2d;
	e->xinc = (e->dx > 0) ? 1 : -1;
	e->yinc = (e->dy > 0) ? 1 : -1;
	e->dx = fabs(e->dx);
	e->dy = fabs(e->dy);
	put_point(tmp, e, getcolor(p1, p2, e, 0));
	e->tx = e->dx / 2;
	e->ty = e->dy / 2;
}

static void		drawline2(t_point *p1, t_point *p2, t_point *tmp, t_env *e)
{
	int		i;

	i = 0;
	while (i < e->dy)
	{
		tmp->y2d += e->yinc;
		e->ty += e->dx;
		if (e->ty >= e->dy)
		{
			e->ty -= e->dy;
			tmp->x2d += e->xinc;
		}
		put_point(tmp, e, getcolor(p1, p2, e, (float)(i / e->dy)));
		i++;
	}
}

static void		drawline(t_point *p1, t_point *p2, t_env *e)
{
	t_point tmp;
	int		i;

	i = 0;
	line_setup(p1, p2, &tmp, e);
	if (e->dx > e->dy)
	{
		while (i < e->dx)
		{
			tmp.x2d += e->xinc;
			e->tx += e->dy;
			if (e->tx >= e->dx)
			{
				e->tx -= e->dx;
				tmp.y2d += e->yinc;
			}
			put_point(&tmp, e, getcolor(p1, p2, e, (float)(i / e->dx)));
			i++;
		}
	}
	else
		drawline2(p1, p2, &tmp, e);
}

void			ft_draw(t_env *e)
{
	t_point p;

	e->y = 0;
	while (e->y < e->lines)
	{
		e->x = 0;
		while (e->pt[e->y][e->x].x != -1)
		{
			p = e->pt[e->y][e->x];
			if ((e->pt[e->y] + e->x + 1)->x != -1)
				drawline(&p, &e->pt[e->y][e->x + 1], e);
			if (e->y + 1 < e->lines && (e->pt[e->y + 1] + e->x)->x != -1)
				drawline(&p, &e->pt[e->y + 1][e->x], e);
			e->x++;
		}
		e->y++;
	}
}
