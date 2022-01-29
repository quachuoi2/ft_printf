/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:54:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/29 09:36:47 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int main()
{
	char a = 'q';
	char *p;

	p = ft_strdup("moro");
	ft_d2b(3);
	//ft_printf("%cuachuoi%d - %p\n", a, 2, p);
	return (0);
}