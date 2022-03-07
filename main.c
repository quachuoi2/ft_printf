/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:54:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/07 17:59:02 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int sixd()
{
	int i;
	i = ft_printf("6d: %6d@\n", 1234);
	ft_printf("%d\n", i);
}

int p_sixd()
{
	int i;
	i = ft_printf("+6d: %+6d@\n", 1234);
	ft_printf("%d\n", i);
}

int n_sixd()
{
	int i;
	i = ft_printf("-6d: %-6d@\n", 1234);
	ft_printf("%d\n", i);
}

int pn_sixd()
{
	int i;
	i = ft_printf("+-6d: %+-6d@\n", 1234);
	ft_printf("%d\n", i);
}

int zerosixd()
{
	int i;
	i = ft_printf("06d: %06d@\n", 1234);
	ft_printf("%d\n", i);
}

int p_zerosixd()
{
	int i;
	i = ft_printf("+06d: %+06d@\n", 1234);
	ft_printf("%d\n", i);
}

int n_zerosixd()
{
	int i;
	i = ft_printf("-06d: %-06d@\n", 1234);
	ft_printf("%d\n", i);
}

int pn_zerosixd()
{
	int i;
	i = ft_printf("+-06d: %+-06d@\n", 1234);
	ft_printf("%d\n", i);
}

int precsixd()
{
	int i;
	i = ft_printf(".6d: %.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int p_precsixd()
{
	int i;
	i = ft_printf("+.6d: %+.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int n_precsixd()
{
	int i;
	i = ft_printf("-.6d: %-.6d@\n", 1234);
	ft_printf("%d\n", i);
}


int pn_precsixd()
{
	int i;
	i = ft_printf("+-.6d: %+-.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int	sixpreconed()
{
	int i;
	i = ft_printf("6.1d: %6.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	p_sixpreconed()
{
	int i;
	i = ft_printf("+6.1d: %+6.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	n_sixpreconed()
{
	int i;
	i = ft_printf("-6.1d: %-6.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	pn_sixpreconed()
{
	int i;
	i = ft_printf("+-6.1d: %+-6.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	oned()
{
	int i;
	i = ft_printf("1d: %1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	p_oned()
{
	int i;
	i = ft_printf("+1d: %+1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	n_oned()
{
	int i;
	i = ft_printf("-1d: %-1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	pn_oned()
{
	int i;
	i = ft_printf("+-1d: %+-1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	preconed()
{
	int i;
	i = ft_printf(".1d: %.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	p_preconed()
{
	int i;
	i = ft_printf("+.1d: %+.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	n_preconed()
{
	int i;
	i = ft_printf("-.1d: %-.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	pn_preconed()
{
	int i;
	i = ft_printf("+-.1d: %+-.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	onepreconed()
{
	int i;
	i = ft_printf("1.1d: %1.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	p_onepreconed()
{
	int i;
	i = ft_printf("+1.1d: %+1.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	n_onepreconed()
{
	int i;
	i = ft_printf("-1.1d: %-1.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	pn_onepreconed()
{
	int i;
	i = ft_printf("+-1.1d: %+-1.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	oneprecsixd()
{
	int i;
	i = ft_printf("1.6d: %1.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int	p_oneprecsixd()
{
	int i;
	i = ft_printf("+1.6d: %+1.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int	n_oneprecsixd()
{
	int i;
	i = ft_printf("-1.6d: %-1.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int	pn_oneprecsixd()
{
	int i;
	i = ft_printf("+-1.6d: %+-1.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int	tenpreconed()
{
	int i;
	i = ft_printf("10.1d: %10.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	p_tenpreconed()
{
	int i;
	i = ft_printf("+10.1d: %+10.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	n_tenpreconed()
{
	int i;
	i = ft_printf("-10.1d: %-10.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	pn_tenpreconed()
{
	int i;
	i = ft_printf("+-10.1d: %+-10.1d@\n", 1234);
	ft_printf("%d\n", i);
}

int	tenprecsixd()
{
	int i;
	i = ft_printf("10.6d: %10.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int	p_tenprecsixd()
{
	int i;
	i = ft_printf("+10.6d: %+10.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int	n_tenprecsixd()
{
	int i;
	i = ft_printf("-10.6d: %-10.6d@\n", 1234);
	ft_printf("%d\n", i);
}

int	pn_tenprecsixd()
{
	int i;
	i = ft_printf("+-10.6d: %+-10.6d@\n", 1234);
	ft_printf("%d\n", i);
}

void bundle()
{
	sixd();
	p_sixd();
	n_sixd();
	pn_sixd();

	zerosixd();
	p_zerosixd();
	n_zerosixd();
	pn_zerosixd();

	precsixd();
	p_precsixd();
	n_precsixd();
	pn_precsixd();

	sixpreconed();
	p_sixpreconed();
	n_sixpreconed();
	pn_sixpreconed();

	oned();
	p_oned();
	n_oned();
	pn_oned();

	preconed();
	p_preconed();
	n_preconed();
	pn_preconed();

	onepreconed();
	p_onepreconed();
	n_onepreconed();
	pn_onepreconed();

	oneprecsixd();
	p_oneprecsixd();
	n_oneprecsixd();
	pn_oneprecsixd();

	tenpreconed();
	p_tenpreconed();
	n_tenpreconed();
	pn_tenpreconed();

	tenprecsixd();
	p_tenprecsixd();
	n_tenprecsixd();
	pn_tenprecsixd();
}

int	main(void)
{
	//bundle();
	char *p = ft_strdup("moro");
	int i;

	i = ft_printf("moromoro %030b\n", 1997);
	ft_printf("42: %d\n", i);
	free(p);
	return (0);
}
