/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:39:42 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/24 11:51:32 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_float(char *base_num, char *decimals, int prec)
{
	ft_putstr(base_num);
	if (prec)
	{
		write(1, ".", 1);
		ft_putstr(decimals);
	}
}

static int	round_base_num(int i, char *base_num)
{
	if (i < 0)
		return (0);
	if (base_num[i] < '9')
	{
		base_num[i]++;
		return (1);
	}
	else
	{
		base_num[i] = '0';
		i--;
		return (round_base_num(i, base_num));
	}
}

static int	round_prev_dec(int i, char *decimals)
{
	if (i < 0)
		return (0);
	if (decimals[i] < '9')
	{
		decimals[i]++;
		return (1);
	}
	else
	{
		decimals[i] = '0';
		i--;
		return (round_prev_dec(i, decimals));
	}
}

static int	set_decimal(int prec, long double lift, char *decimals)
{
	int	i;
	int	ret;

	ret = 1;
	if (lift < 0)
		lift *= -1;
	lift -= (long long)lift;
	lift *= 10;
	i = -1;
	while (++i < prec - 1)
	{
		decimals[i] = (long long)lift + '0';
		lift -= (long long)lift;
		lift *= 10;
	}
	if (lift - (long long)lift >= 0.5)
		lift++;
	if (lift >= 10.0)
	{
		lift = 0;
		ret = round_prev_dec(i - 1, decimals);
	}
	decimals[i++] = (long long)lift + '0';
	decimals[i] = '\0';
	return (ret);
}

int	ft_putfloat(long double lift, int prec)
{
	char	*tmp;
	char	base_num[25];
	char	decimals[25];
	int		base_len;
	int		ret;

	tmp = ft_itoa((long long)lift);
	ft_strcpy(base_num, tmp);
	base_len = ft_strlen(base_num);
	free(tmp);
	ret = 0;
	if (!set_decimal(prec, lift, decimals))
	{
		if (!round_base_num(base_len - 1, base_num))
		{
			base_num[0] = '1';
			base_num[base_len] = '0';
			base_num[base_len + 1] = '\0';
			ret = 1;
		}
	}
	print_float(base_num, decimals, prec);
	return (ret);
}
