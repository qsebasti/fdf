/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:52:25 by qsebasti          #+#    #+#             */
/*   Updated: 2018/01/10 17:25:27 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			fdf_error(int a)
{
	if (a == 1)
		ft_putendl("usage: ./fdf map_file");
	else if (a == 2)
		ft_putendl("open error");
	else if (a == 3)
		ft_putendl("read error");
	else if (a == 4)
		ft_putendl("malloc error");
	else if (a == 5)
		ft_putendl("error");
	exit(1);
	return (0);
}

static int	exitcross(t_env *e)
{
	free(e->str);
	exit(1);
	return (1);
}

int			main(int ac, char **av)
{
	t_env e;

	if (ac != 2)
		return (fdf_error(1));
	ft_set(&e);
	if ((start(av[1], &e) < 1))
		return (0);
	if (!(e.mlx = mlx_init()) ||
			!(e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "fdf")))
		return (fdf_error(5));
	e.str = ft_strdup(av[1]);
	mlx_hook(e.win, 2, 1L << 0, &keypress, &e);
	mlx_hook(e.win, 3, 1L << 1, &keyrelease, &e);
	mlx_hook(e.win, 17, 1L << 17, &exitcross, &e);
	mlx_loop_hook(e.mlx, &exposehook, &e);
	mlx_loop(e.mlx);
	return (0);
}
