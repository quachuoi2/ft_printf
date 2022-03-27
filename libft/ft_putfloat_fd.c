/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:56:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/27 01:56:48 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat_fd(long double lift, int i, int fd)
{
	ft_putnbr_fd((long long int)lift, fd);
	if (i > 0)
	{
		if (lift < 0)
			lift *= -1;
		write(fd, ".", 1);
		lift -= (long long int)lift;
		while (i > 0)
		{
			lift *= 10;
			if (lift == 0)
				write (fd, "0", 1);
			i--;
		}
		if (lift != 0)
		{
			if (lift - (long long int)lift >= 0.5)
				ft_putnbr_fd((long long int)lift + 1, fd);
			else
				ft_putnbr_fd((long long int)lift, fd);
		}
	}
}
