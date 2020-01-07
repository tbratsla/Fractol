/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:46:22 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/22 14:46:22 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/frac.h"
#include <stdio.h>

void	ft_initialize(t_fractol *fract)
{
	fract->zoom = 100;
	fract->movex = -5.0;
	fract->movey = -4.0;
	fract->maxiterations = 80;
	fract->color = 0x0c0200;
	fract->cre = -0.75;
	fract->cim = 0.11;
	fract->flag = 0;
	fract->y = 0;
	fract->x = 0;
}

void	*frac(void *data)
{
	int			i;
	t_fractol	*fract;

	fract = (void *)data;
	fract->pr = 0.0;
	fract->pi = 0.0;
	fract->newim = 0;
	fract->newre = 0;
	fract->y = HEIGHT / THR * fract->thr_id;
	while (fract->y < HEIGHT / THR * (fract->thr_id + 1))
	{
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			i = 0;
			calc_fract(fract, i);
		}
		fract->y++;
	}
	return (data);
}

int		main(int ac, char **av)
{
	t_fractol *fract;

	if (!(valid(av, ac)))
		return (0);
	fract = ft_memalloc(sizeof(t_fractol));
	fract->win = ft_memalloc(sizeof(t_draw));
	fract->number = ft_atoi(av[1]);
	fract->win->mlx = mlx_init();
	fract->win->window = mlx_new_window(fract->win->mlx, 1000, 800, "Fract'ol");
	fract->win->window1 = mlx_new_window(fract->win->mlx, 300, 300, "Menu");
	menu(fract->win->mlx, fract->win->window1);
	fract->win->img = mlx_new_image(fract->win->mlx, 1000, 800);
	fract->win->img_ptr = (int*)mlx_get_data_addr(fract->win->img,\
				&fract->win->bpp, &fract->win->sl, &fract->win->endian);
	ft_initialize(fract);
	flow(fract);
	mlx_hook(fract->win->window, 2, 0, push_key, fract);
	mlx_hook(fract->win->window, 4, 0, press_mouse, fract);
	mlx_hook(fract->win->window, 6, 1L < 6, julia_mouse, fract);
	system("afplay sound.mp3&");
	mlx_loop(fract->win->mlx);
}

void	menu(void *mlx, void *wind)
{
	mlx_string_put(mlx, wind, 10, 10, 0xffffff, "Menu");
	mlx_string_put(mlx, wind, 10, 25, 0xffffff, "1 - Julia");
	mlx_string_put(mlx, wind, 10, 40, 0xffffff, "2 - Mandelbrot");
	mlx_string_put(mlx, wind, 10, 55, 0xffffff, "3 - Burning Ship");
	mlx_string_put(mlx, wind, 10, 70, 0xffffff, "4 - Celtic Mandelbrot");
	mlx_string_put(mlx, wind, 10, 85, 0xffffff, "5 - Celtic Mandelbar");
	mlx_string_put(mlx, wind, 10, 100, 0xffffff, "6 - Berry");
	mlx_string_put(mlx, wind, 10, 115, 0xffffff, "7 - Rhombus");
	mlx_string_put(mlx, wind, 10, 130, 0xffffff, "8 - Tambourine");
	mlx_string_put(mlx, wind, 10, 145, 0xffffff, "9 - Candle");
	mlx_string_put(mlx, wind, 10, 160, 0xffffff, "0 - What do you see?");
	mlx_string_put(mlx, wind, 10, 175, 0xffffff, "+ - Change count iter");
	mlx_string_put(mlx, wind, 10, 190, 0xffffff, "- - Change count iter");
	mlx_string_put(mlx, wind, 10, 205, 0xffffff, "Mouse 1, Mouse 2 - move");
	mlx_string_put(mlx, wind, 10, 220, 0xffffff, "Mouse 4, Mouse 5 - scale");
	mlx_string_put(mlx, wind, 10, 235, 0xffffff, "Q - Stop Julia");
	mlx_string_put(mlx, wind, 10, 250, 0xffffff, "W - Move Julia");
	mlx_string_put(mlx, wind, 10, 265, 0xffffff, "ESC - exit");
}
