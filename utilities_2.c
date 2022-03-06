/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:19:29 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/06 16:23:07 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_flag(int ammount, char c)
{
	while (ammount-- > 0)
		write(1, &c, 1);
}

int	ft_isacceptable(char c)
{
	if (c == ' ' || c == '#' || c == '-' || c == '+' || c == '.'
		|| c == '@' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}
