/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:46:34 by tbratsla          #+#    #+#             */
/*   Updated: 2019/03/22 14:46:34 by tbratsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

# include <math.h>
# include "mlx.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# define WIDTH 1000
# define HEIGHT 800
# define THR 20

typedef struct		s_draw
{
	void			*mlx;
	void			*window;
	void			*window1;
	void			*img;
	int				*img_ptr;
	int				bpp;
	int				sl;
	int				endian;
}					t_draw;

typedef struct		s_fractol
{
	t_draw			*win;
	int				number;
	double			zoom;
	double			movex;
	double			movey;
	double			cre;
	double			cim;
	int				color;
	int				maxiterations;
	int				flag;
	int				thr_id;
	int				y;
	int				x;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			rere;
	double			imim;
	double			pr;
	double			pi;
}					t_fractol;

int					push_key(int key, t_fractol *fract);
int					main(int ac, char **av);
void				*frac(void *data);
int					press_mouse(int button, int x, int y, t_fractol *fract);
int					press_mouse1(int button, t_fractol *fract);
int					julia_mouse(int x, int y, t_fractol *fract);
void				flow(t_fractol *fract);
void				ft_initialize(t_fractol *fract);
int					push_key1(int key, t_fractol *fract);
int					push_key2(int key, t_fractol *fract);
int					push_key3(int key, t_fractol *fract);
void				calc_fract(t_fractol *fract, int i);
void				calc1(t_fractol *fract);
void				calc2(t_fractol *fract);
void				calc3(t_fractol *fract);
void				calc4(t_fractol *fract);
void				menu(void *mlx, void *wind);
void				put_error(void);
int					valid(char **av, int ac);

#endif
