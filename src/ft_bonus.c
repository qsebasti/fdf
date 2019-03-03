/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:14:02 by qsebasti          #+#    #+#             */
/*   Updated: 2018/01/18 17:37:34 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int		keyrot(t_env *e)
{
	if (e->key[KEY_4])
		e->rotx += ROT;
	if (e->key[KEY_5])
		e->roty += ROT;
	if (e->key[KEY_6])
		e->rotz += ROT;
	if (e->key[KEY_7])
		e->rotx -= ROT;
	if (e->key[KEY_8])
		e->roty -= ROT;
	if (e->key[KEY_9])
		e->rotz -= ROT;
	if (e->key[KEY_DEL])
		e->zr = 1;
	return (0);
}

int				keyhook(t_env *e)
{
	if (e->key[KEY_ESC])
		exit(1);
	if (e->key[KEY_UP] && e->h >= -HEIGHT / 2)
		e->h -= 10;
	if (e->key[KEY_LEFT] && e->w >= -WIDTH / 2)
		e->w -= 10;
	if (e->key[KEY_DOWN] && e->h <= HEIGHT + HEIGHT / 2)
		e->h += 10;
	if (e->key[KEY_RIGHT] && e->w <= WIDTH + WIDTH / 2)
		e->w += 10;
	if (e->key[KEY_PLUS] && e->pix <= 200)
		e->pix++;
	if (e->key[KEY_MINUS] && e->pix > 1)
		e->pix--;
	if (e->key[KEY_1] && e->gap >= 0.1)
		e->gap -= 0.05;
	if (e->key[KEY_2] && e->gap < 2)
		e->gap += 0.05;
	keyrot(e);
	move(e);
	return (1);
}

static void		reset(t_point *p, t_env *e)
{
	if (e->zr)
	{
		e->w = WIDTH / 3;
		e->h = HEIGHT / 3;
		e->gap = 0.2;
		e->rotx = 0;
		e->roty = 0;
		e->rotz = 0;
		e->pix = PIX;
		p->x2d = (((p->x * CTE1) - (p->y * CTE2)) * e->pix) + e->w;
		p->y2d = (((p->y * CTE3) + (p->x * CTE4) - p->z * e->gap) * e->pix) +
			e->h;
	}
	p->x2d = (((p->tmpx * CTE1) - (CTE2 * p->tmpy)) * e->pix) + e->w;
	p->y2d = (((p->tmpy * CTE3) + (p->tmpx * CTE4) - p->z * e->gap) *
			e->pix) + e->h;
}

static void		rot(t_point *p, t_env *e)
{
	double a;
	double b;

	if (e->rotx >= M_PI * 2 || e->rotx <= -M_PI * 2)
		e->rotx = 0;
	if (e->roty >= M_PI * 2 || e->roty <= -M_PI * 2)
		e->roty = 0;
	if (e->rotz >= M_PI * 2 || e->rotz <= -M_PI * 2)
		e->rotz = 0;
	p->tmpx = p->x * cos(e->rotz) - p->y * sin(e->rotz);
	p->tmpy = p->x * sin(e->rotz) + p->y * cos(e->rotz);
	a = p->tmpy;
	p->tmpy = a * cos(e->rotx) - (p->z * e->gap) * sin(e->rotx);
	b = a * sin(e->rotx) + (p->z * e->gap) * cos(e->rotx);
	a = p->tmpx;
	p->tmpx = a * cos(e->roty) - b * sin(e->roty);
}

void			move(t_env *e)
{
	e->y = 0;
	while (e->y < e->lines)
	{
		e->x = 0;
		while (e->pt[e->y][e->x].x != -1)
		{
			rot(&e->pt[e->y][e->x], e);
			reset(&e->pt[e->y][e->x], e);
			e->x++;
		}
		e->y++;
	}
	e->zr = 0;
}
