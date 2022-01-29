/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:12 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/29 11:12:25 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
#include <stdio.h> //REMOVE

int	ft_printf(const char *restrict format, ...);

#endif
