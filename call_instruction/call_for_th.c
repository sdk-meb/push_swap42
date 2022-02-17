/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_for_th.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:57:40 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/17 12:57:47 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "call_inst.h"

void	call_inst_th(int count, t_list **a, char name_stk)
{
	if (count > 2 && (*a)->val > (*a)->next->val
		&& (*a)->val > (*a)->prev->val)
		retate_stk(a, name_stk);
	else if (count > 2 && (*a)->val < (*a)->next->val
		&& (*a)->next->val > (*a)->prev->val)
		rev_retate_stk(a, name_stk);
	if (count > 1 && (*a)->val > (*a)->next->val)
		swap_stk(a, name_stk);
	return ;
}
