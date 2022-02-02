/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:12 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/02 14:26:05 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
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
	char	conv;
}				t_order;

//libftprintf.c
int				ft_printf(const char *restrict format, ...);

//prefix.c
void			check_prefix(char *fmt, t_order *order);
void			check_flag(char *fmt, t_order *order);
void			check_conv(char *fmt, t_order *order);

//utilities.c
void			initialize_t_order(t_order *order);

#endif
