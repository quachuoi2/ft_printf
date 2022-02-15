/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_og.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:54:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/15 02:17:37 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int sixd()
{
	int i;
	i = printf("6d: %6d@\n", 123);
	printf("%d\n", i);

}

int p_sixd()
{
	int i;
	i = printf("+6d: %+6d@\n", 123);
	printf("%d\n", i);

}
int zerosixd()
{
	int i;
	i = printf("06d: %06d@\n", 123);
	printf("%d\n", i);

}

int p_zerosixd()
{
	int i;
	i = printf("+06d: %+06d@\n", 123);
	printf("%d\n", i);

}

int precsixd()
{
	int i;
	i = printf(".6d: %.6d@\n", 123);
	printf("%d\n", i);

}

int p_precsixd()
{
	int i;
	i = printf("+.6d: %+.6d@\n", 123);
	printf("%d\n", i);

}

int	sixpreconed()
{
	int i;
	i = printf("6.1d: %6.1d@\n", 123);
	printf("%d\n", i);

}

int	p_sixpreconed()
{
	int i;
	i = printf("+6.1d: %+6.1d@\n", 123);
	printf("%d\n", i);

}

int	oned()
{
	int i;
	i = printf("1d: %1d@\n", 123);
	printf("%d\n", i);

}

int	p_oned()
{
	int i;
	i = printf("+1d: %+1d@\n", 123);
	printf("%d\n", i);

}

int	preconed()
{
	int i;
	i = printf(".1d: %.1d@\n", 123);
	printf("%d\n", i);

}

int	p_preconed()
{
	int i;
	i = printf("+.1d: %+.1d@\n", 123);
	printf("%d\n", i);

}
int	onepreconed()
{
	int i;
	i = printf("1.1d: %1.1d@\n", 123);
	printf("%d\n", i);

}

int	p_onepreconed()
{
	int i;
	i = printf("+1.1d: %+1.1d@\n", 123);
	printf("%d\n", i);

}

int	oneprecsixd()
{
	int i;
	i = printf("1.6d: %1.6d@\n", 123);
	printf("%d\n", i);

}

int	p_oneprecsixd()
{
	int i;
	i = printf("+1.6d: %+1.6d@\n", 123);
	printf("%d\n", i);

}

int	tenpreconed()
{
	int i;
	i = printf("10.1d: %10.1d@\n", 123);
	printf("%d\n", i);

}

int	p_tenpreconed()
{
	int i;
	i = printf("+10.1d: %+10.1d@\n", 123);
	printf("%d\n", i);

}

int	tenprecsixd()
{
	int i;
	i = printf("10.6d: %10.6d@\n", 123);
	printf("%d\n", i);

}

int	p_tenprecsixd()
{
	int i;
	i = printf("+10.6d: %+10.6d@\n", 123);
	printf("%d\n", i);

}

int	main(void)
{
	sixd();
	p_sixd();
	zerosixd();
	p_zerosixd();
	precsixd();
	p_precsixd();
	sixpreconed();
	p_sixpreconed();
	oned();
	p_oned();
	preconed();
	p_preconed();
	onepreconed();
	p_onepreconed();
	oneprecsixd();
	p_oneprecsixd();
	tenpreconed();
	p_tenpreconed();
	tenprecsixd();
	p_tenprecsixd();
	return (0);
}
