/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:29:50 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/26 15:29:51 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/frac.h"

void	flow(t_fractol *fract)
{
	pthread_t	thr[THR];
	t_fractol	mass[THR];

	fract->thr_id = 0;
	while (fract->thr_id < THR)
	{
		ft_memcpy((void *)&mass[fract->thr_id], (void *)fract, \
			sizeof(t_fractol));
		mass[fract->thr_id].y = fract->thr_id * 50;
		pthread_create(&thr[fract->thr_id], NULL, frac,\
			&mass[fract->thr_id]);
		fract->thr_id++;
	}
	fract->thr_id = 0;
	while (fract->thr_id < THR)
	{
		pthread_join(thr[fract->thr_id], NULL);
		fract->thr_id++;
	}
	mlx_put_image_to_window(fract->win->mlx, fract->win->window, \
							fract->win->img, 0, 0);
}
