/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:23:46 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/14 12:25:23 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include "../sorted.h"

char	module(int *val);
char	evan_odd(int *val, char p, int to_p);
int		cmp_val(int y, int x, char triat);
int		low_val(int x, bool rest);
int		high_val(int x, bool rest);

#endif
