/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:59:17 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/11 17:34:40 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef     SORTED_H
# define    SORTED_H

# include "list/list.h"
# include "call_instruction/call_inst.h"
# include "math/math.h"
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>
typedef struct integer {
	int	i;
	int	j;
	int	n;
}t_intgr;

int		ft_atoi(t_list **lstclr, char *str);
void	push_stk(t_list **stk, t_list **stk_to, char c);
void	swap_stk(t_list **stk, char name_stk);
void	retate_stk(t_list **stk, char name_stk);
void	rev_retate_stk(t_list **stk, char name_stk);
int     check_dup_sort(t_list	**stk);
char	**ft_split(char *s, char c, int *count);

#endif
