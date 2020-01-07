/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:16:19 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/26 17:16:21 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/frac.h"

void	calc_fract(t_fractol *fract, int i)
{
	fract->pr = fract->x * 1.0 / fract->zoom + fract->movex;
	fract->pi = fract->y * 1.0 / fract->zoom + fract->movey;
	fract->oldre = fract->pr;
	fract->oldim = fract->pi;
	while (i < fract->maxiterations && (fract->oldre *\
			fract->oldre + fract->oldim * fract->oldim) < 16)
	{
		calc1(fract);
		i++;
	}
	fract->x++;
	if (i == fract->maxiterations)
	{
		if (fract->x < WIDTH && fract->y < HEIGHT)
			*(fract->win->img_ptr + (fract->y * WIDTH\
									 + fract->x)) = fract->color; //fract->win->img_ptr[fract->y * WIDTH + fract->x]
	}
	else
	{
		if (fract->x < WIDTH && fract->y < HEIGHT)
			*(fract->win->img_ptr + (fract->y * WIDTH\
				+ fract->x)) = fract->color * i;
	}
}

void	calc1(t_fractol *fract)
{
	if (fract->number == 2)
	{
		fract->newre = fract->oldre * fract->oldre -\
		fract->oldim * fract->oldim + fract->pr;
		fract->newim = 2 * fract->oldre * fract->oldim + fract->pi;
	}
	if (fract->number == 3)
	{
		fract->newre = fract->oldre * fract->oldre -\
		fract->oldim * fract->oldim + fract->pr;
		fract->newim = 2 * fabs(fract->oldre * fract->oldim) + fract->pi;
	}
	if (fract->number == 4)
	{
		fract->newre = fabs(fract->oldre * fract->oldre\
							- fract->oldim * fract->oldim) + fract->pr;
		fract->newim = 2 * fract->oldre * fract->oldim + fract->pi;
	}
	calc2(fract);
}

void	calc2(t_fractol *fract)
{
	if (fract->number == 7)
	{
		fract->newre = fract->oldre * fract->oldre - fract->oldre +\
		fract->oldim * fract->oldim + fract->pr;
		fract->newim = 2 * fract->oldre * fract->oldim -\
		fract->oldim + fract->pi;
	}
	if (fract->number == 8)
	{
		fract->newre = fract->oldre * fract->oldre * fract->oldre + 3 *\
		fract->oldre * fract->oldim * fract->oldim + fract->pr;
		fract->newim = 3 * fract->oldre * fract->oldre * fract->oldim -\
		fract->oldim * fract->oldim * fract->oldim + fract->pi;
	}
	calc4(fract);
}

void	calc3(t_fractol *fract)
{
	if (fract->number == 9)
	{
		fract->newre = fract->oldre * fract->oldre * fract->oldre + 3 *\
		fract->oldre * fract->oldim * fract->oldim + fract->oldre + fract->pr;
		fract->newim = 3 * fract->oldre * fract->oldre * fract->oldim -\
		fract->oldim * fract->oldim * fract->oldim + fract->pi;
	}
	if (fract->number == 0)
	{
		fract->newre = fract->oldre * fract->oldre * fract->oldre *\
		fract->oldre - 6 * fract->oldre * fract->oldre * fract->oldim *\
		fract->oldim + fract->oldre + fract->oldim * fract->oldim *\
		fract->oldim * fract->oldim + fract->pr;
		fract->newim = 4 * fract->oldre * fract->oldre * fract->oldre *\
		fract->oldim - 4 * fract->oldre * fract->oldim * fract->oldim *\
		fract->oldim + fract->pi;
	}
	if (fract->number == 5)
	{
		fract->newre = fabs(fract->oldre * fract->oldre -\
							fract->oldim * fract->oldim) + fract->pr;
		fract->newim = -2 * fract->oldre * fract->oldim + fract->pi;
	}
	fract->oldre = fract->newre;
	fract->oldim = fract->newim;
}

void	calc4(t_fractol *fract)
{
	if (fract->number == 1)
	{
		fract->newre = fract->oldre * fract->oldre - fract->oldim * fract->oldim + fract->cre;
		fract->newim = 2 * fract->oldre * fract->oldim + fract->cim;
	}
	if (fract->number == 6)
	{
		fract->newre = -fract->pr * fract->oldre * fract->oldre + fract->pr\
		* fract->oldre + fract->pr * fract->oldim * fract->oldim + 2 *\
		fract->oldre * fract->pi * fract->oldim - fract->oldim * fract->pi;
		fract->newim = -2 * fract->oldre * fract->oldim * fract->pr +\
		fract->pr * fract->oldim - fract->oldre * fract->oldre * fract->pi\
		+ fract->oldre * fract->pi + fract->pi * fract->oldim * fract->oldim;
	}
	calc3(fract);
}
