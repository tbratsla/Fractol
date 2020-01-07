/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:46:06 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/27 10:46:07 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/frac.h"

int		valid(char **av, int ac)
{
	if (ac != 2)
	{
		put_error();
		return (0);
	}
	if (!(ft_strlen(av[1]) > 0 && ft_strlen(av[1]) < 2 &&\
		av[1][0] >= '0' && av[1][0] <= '9'))
	{
		put_error();
		return (0);
	}
	return (1);
}

void	put_error(void)
{
	ft_putendl("./fractol 1 - Julia");
	ft_putendl("./fractol 2 - Mandelbrot");
	ft_putendl("./fractol 3 - Burning Ship");
	ft_putendl("./fractol 4 - Celtic Mandelbrot");
	ft_putendl("./fractol 5 - Celtic Mandelbar");
	ft_putendl("./fractol 6 - Berry");
	ft_putendl("./fractol 7 - Rhombus");
	ft_putendl("./fractol 8 - Tambourine");
	ft_putendl("./fractol 9 - Candle");
	ft_putendl("./fractol 0 - What do you see?");
}
