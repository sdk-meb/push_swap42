/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 01:49:59 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/14 12:19:07 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "math.h"

char	module(int *val)
{
	if (*val >= 0)
		return ('P');
	*val = *val * (-1);
	return ('N');
}

int	cmp_val(int y, int x, char triat)
{
	if (triat == 'M')
	{
		if (y < x)
			return (x);
		return (y);
	}
	if (y < x)
		return (y);
	return (x);
}

char	evan_odd(int *val, char p, int to_p)
{
	int	n;

	n = *val / 2;
	if ((n * 2) == *val)
	{
		if (p == 'O')
			*val += to_p;
		return ('E');
	}
	if (p == 'E')
		*val += to_p;
	return ('O');
}

int	low_val(int x, bool rest)
{
	static int	t;

	if ((x != -33 && x < t) || rest)
		t = x;
	return (t);
}

int	high_val(int x, bool rest)
{
	static int	t;

	if ((x != -33 && x > t) || rest)
		t = x;
	return (t);
}
