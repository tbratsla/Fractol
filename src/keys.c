/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:27:20 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/26 16:27:20 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/frac.h"

int		push_key2(int key, t_fractol *fract)
{
	if (key == 22 || key == 88)
	{
		ft_initialize(fract);
		fract->number = 6;
		flow(fract);
	}
	if (key == 26 || key == 89)
	{
		ft_initialize(fract);
		fract->number = 7;
		flow(fract);
	}
	if (key == 28 || key == 91)
	{
		ft_initialize(fract);
		fract->number = 8;
		flow(fract);
	}
	if (key == 25 || key == 92)
	{
		ft_initialize(fract);
		fract->number = 9;
		flow(fract);
	}
	return (0);
}

int		push_key3(int key, t_fractol *fract)
{
	if (key == 19 || key == 84)
	{
		ft_initialize(fract);
		fract->number = 2;
		flow(fract);
	}
	if (key == 20 || key == 85)
	{
		ft_initialize(fract);
		fract->number = 3;
		flow(fract);
	}
	if (key == 21 || key == 86)
	{
		ft_initialize(fract);
		fract->number = 4;
		flow(fract);
	}
	if (key == 23 || key == 87)
	{
		ft_initialize(fract);
		fract->number = 5;
		flow(fract);
	}
	return (0);
}
