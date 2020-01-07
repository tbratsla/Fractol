/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:30:17 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/26 15:30:18 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/frac.h"

int		julia_mouse(int x, int y, t_fractol *fract)
{
	if (fract->number == 1 && fract->flag == 0)
	{
		if (x < 500 && y > 0)
		{
			fract->cre += 0.04;
			fract->cim += -0.017;
		}
		else
		{
			fract->cre -= 0.04;
			fract->cim -= -0.017;
		}
		flow(fract);
	}
	return (0);
}

int		press_mouse(int button, int x, int y, t_fractol *fract)
{
	if (button == 5)
	{
		fract->movex = (x / fract->zoom + fract->movex)\
		- (x / (fract->zoom / 0.9));
		fract->movey = (y / fract->zoom + fract->movey)\
		- (y / (fract->zoom / 0.9));
		fract->zoom /= 0.9;
		fract->maxiterations++;
	}
	if (button == 4)
	{
		fract->movex = (x / fract->zoom + fract->movex)\
		- (x / (fract->zoom * 0.9));
		fract->movey = (y / fract->zoom + fract->movey)\
		- (y / (fract->zoom * 0.9));
		fract->zoom *= 0.9;
		fract->maxiterations--;
	}
	press_mouse1(button, fract);
	flow(fract);
	return (0);
}

int		press_mouse1(int button, t_fractol *fract)
{
	if (button == 1)
	{
		fract->movex -= 20 / fract->zoom;
		fract->movey -= 20 / fract->zoom;
	}
	if (button == 2)
	{
		fract->movex += 20 / fract->zoom;
		fract->movey += 20 / fract->zoom;
	}
	return (0);
}

int		push_key(int key, t_fractol *fract)
{
	if (key == 53)
	{
		free(fract->win);
		free(fract);
		system("killall afplay");
		exit(0);
	}
	if (key == 18 || key == 83)
	{
		ft_initialize(fract);
		fract->number = 1;
		flow(fract);
	}
	push_key1(key, fract);
	push_key2(key, fract);
	push_key3(key, fract);
	return (0);
}

int		push_key1(int key, t_fractol *fract)
{
	if (key == 29 || key == 82)
	{
		ft_initialize(fract);
		fract->number = 0;
		flow(fract);
	}
	if (key == 12)
		fract->flag = 1;
	if (key == 13)
	{
		fract->flag = 0;
	}
	if (key == 69 && fract->maxiterations < 400)
	{
		fract->maxiterations += 10;
		flow(fract);
	}
	if (key == 78 && fract->maxiterations > 50)
	{
		fract->maxiterations -= 10;
		flow(fract);
	}
	return (0);
}
