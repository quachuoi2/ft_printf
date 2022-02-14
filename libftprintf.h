/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:12 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/14 06:17:18 by qnguyen          ###   ########.fr       */
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
	int		mfw;
	int		space;
	int		hash;
	int		zero;
	int		neg;
	int		pos;
	int		prec;
	char	flag[2];
	char	conv;
	int		base;
}				t_order;

//libftprintf.c
int		ft_printf(const char *format, ...);

//prefix.c
void	check_prefix(char **fmt, t_order *order);
void	check_flag(char **fmt, t_order *order);
void	check_conv(char **fmt, t_order *order);

//utilities.c
void	initialize_t_order(t_order *order);
//int				repeated_flag(t_order order);
void	int_converter(unsigned long long int *u, long long *n, t_order order);
int		ft_isacceptable(char c);
void	bundling_bundler(int *i, void (*f)(t_order), t_order *order);

//print_dif.c
int		dif(t_order order, va_list ap);

//print_csp.c
int		cs(t_order order, va_list ap);

//print_ouxX.c
int		pouxx(t_order order, va_list ap);

//print_flags.c
void	hash(t_order order);
void	spc_pos(t_order order);
int		mfw(int i, t_order order);
int		prec(int i, t_order *order);

#endif
