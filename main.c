/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:54:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/02 15:33:47 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <float.h>
// Standard integers
#include <limits.h>
// Fixed width, minimum width, fast integers
#include <stdint.h>
// Extended multibyte/wide characters
#include <wchar.h>

 int	main(void)
{
	char	a = 'q';
	int	i;
	char	*p;

	p = ft_strdup("moro");
	//ft_printf("ft - %cuachuoi%d\n%s - %p\n", a, 2, p, p);
	i = printf("%+d\n", 42);
	printf("%d\n", i);
	free(p);
	return (0);
}
