/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:12 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/14 22:04:12 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h> //REMOVE

typedef struct s_order
{
	char	space;
	char	hash;
	char	zero;
	char	neg;
	char	pos;
	char	base;
	char	negative_num;
	char	color;
	char	conv;
	int		mfw;
	int		prec;
	int		num_of_padding;
	int		num_of_zeros;
	int		func_idx;
	char	flag[2];
}				t_order;

typedef int	t_function(t_order *order, va_list ap);

//libftprintf.c
int		ft_printf(const char *format, ...);
int		convert(t_order *order, va_list ap, char *og_fmt, char *fmt);
int		take_subway_order(char **fmt, va_list ap, t_order *order);

//prefix.c
void	helping_helper(t_order *order, char fmt);
void	check_prefix(char **fmt, t_order *order, va_list ap);
void	check_flag(char **fmt, t_order *order);
void	check_conv(char **fmt, t_order *order);
void	conversion_appropriation(t_order *order);

//utilities.c
void	initialize_t_order(t_order *order);
void	int_converter(unsigned long long int *u, long long *n, t_order *order);
void	bundling_bundler(int *length, int (*f)(t_order *), t_order *order);
int		check_value(unsigned long long u, long long int *n, t_order *order);

//utilities_2.c
void	put_flag(int ammount, char c);
void	a_wild_mfw_appeared(t_order *order, va_list ap, char m_p);
void	mfw_prec_assigner(t_order *order, char **fmt, va_list ap);
void	write_color(char **fmt, char *default_color);

//printer.c
int		put_c(t_order *order, va_list ap);
int		put_s(t_order *order, va_list ap);
int		put_d(t_order *order, va_list ap);
int		put_f(t_order *order, va_list ap);
int		put_pbouxx(t_order *order, va_list ap);

//put_flags.c
int		hash_pos_spc(t_order *order);
int		mfw(int length, t_order *order, int (*f)(t_order *));
int		cal_zero(int length, t_order *order);
int		cal_padding(int length, t_order *order);
#endif
