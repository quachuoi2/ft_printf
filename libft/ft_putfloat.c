/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:39:42 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/19 08:31:02 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(long double lift, int prec)
{
	long long	main_num;
	int			i;

	main_num = (long long)lift;
	if (prec > 0)
	{
		if (lift < 0)
			lift *= -1;
		lift -= main_num;
		i = 0;
		while (i++ < prec)
			lift *= 10;
		ft_putnbr((long long)main_num + (lift - (long long)lift >= 0.5));
		if (prec)
		{
			write(1, ".", 1);
			while (prec-- > ft_diglen((long long)lift))
				write (1, "0", 1);
			if (lift)
				ft_putnbr((long long)lift);
			else
				while (prec-- > 0)
					write (1, "0", 1);
		}
	}
}
