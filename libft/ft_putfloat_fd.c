/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:56:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/24 11:49:47 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_float(char *base_num, char *decimals, int prec, int fd)
{
	ft_putstr_fd(base_num, fd);
	if (prec)
	{
		write(fd, ".", 1);
		ft_putstr_fd(decimals, fd);
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

int	ft_putfloat_fd(long double lift, int prec, int fd)
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
	print_float(base_num, decimals, prec, fd);
	return (ret);
}

/* print float without using string */
/* limited to 18 decimals */

/* static int	number_rounding(int prec, int *i, long long *main_num,
		long double *lift)
{
	int	extra_digit;
	int	rounding;

	extra_digit = -1;
	rounding = 0;
	if (*lift - (long long)*lift >= 0.5)
	{
		(*lift)++;
		rounding = 1;
	}
	*i = ft_diglen((long long)*lift);
	if (*i > prec && rounding)
	{
		(*main_num)++;
		*lift = 0;
		extra_digit = (*main_num) % 10;
	}
	return (!extra_digit);
}

int	ft_putfloat_fd(long double lift, int prec, int fd)
{
	long long	main_num;
	int			i;
	int			extra_rounding_digit;

	main_num = (long long)lift;
	lift -= main_num;
	if (lift < 0)
		lift *= -1;
	lift *= ft_pow(10, prec);
	extra_rounding_digit = number_rounding(prec, &i, &main_num, &lift);
	ft_putnbr_fd(main_num, fd);
	if (prec)
	{
		write(fd, ".", 1);
		while (prec-- > i)
			write(fd, "0", 1);
		if (!lift)
			while (prec-- >= 0)
				write(fd, "0", 1);
		else
			ft_putnbr_fd((long long)lift, fd);
	}
	return (extra_rounding_digit);
} */
