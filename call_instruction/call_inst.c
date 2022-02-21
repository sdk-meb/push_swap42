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

void	call_inst_fore(int c_v, t_list **a, t_list **b)
{
	push_stk(a, b, 'b');
	call_inst_th(3, a, 'a');
	while (c_v--)
	{
		if (c_v == 3 && ((*b)->val < (*a)->val || (*b)->val > (*a)->prev->val))
		{
			push_stk(b, a, 'a');
			if ((*a)->val > (*a)->prev->val)
				retate_stk(a, 'a');
			break ;
		}
		if (*b && ((*b)->val < (*a)->val && (*b)->val > (*a)->prev->val))
			push_stk(b, a, 'a');
		retate_stk(a, 'a');
	}
}

void	call_inst_five(int c_v, t_list **a, t_list **b)
{
	t_list	*p;
	int		val[2];

	p = (*a);
	val[0] = p->val;
	val[1] = val[0];
	while (p)
	{
		if (val[0] > p->val)
			val[0] = p->val;
		if (val[1] < p->val)
			val[1] = p->val;
		p = p->next;
	}
	while (c_v > 3)
	{
		if (val[0] == (*a)->val && c_v--)
			push_stk(a, b, 'b');
		else if (val[1] == (*a)->val && c_v--)
			push_stk(a, b, 'b');
		else
			retate_stk(a, 'a');
	}
	call_inst_th(3, a, 'a');
	push_stk(b, a, 'a');
	if (val[1] == (*a)->val)
		retate_stk(a, 'a');
	push_stk(b, a, 'a');
	if (val[1] == (*a)->val)
		retate_stk(a, 'a');
}

void	call_inst_plus(int c_v, t_list **a, t_list **b)
{
	static int	c_;

	if (!c_)
		c_ = c_v;
	while (--c_ > (c_v / 2))
		push_stk(a, b, 'b');
//	if ((*a)->val > (*a)->next->val && (*b)->val < (*b)->next->val)
//	{
//		swap_stk(a, 'N');
//		swap_stk(b, 's');
//	}
//	else if ((*a)->val > (*a)->next->val)
//		swap_stk(a, 'a');
	if ((*b)->val < (*b)->next->val)
		swap_stk(b, 'b');
	else
	{
		retate_stk(a, 'N');
		retate_stk(b, 's');
		call_inst_plus(c_v, a, b);
		c_++;
		return ;
	}
	if (!check_dup_sort(a))
		return ;
	if (c_ + 1 > (c_v / 2))
	{
		rev_retate_stk(a, 'N');
		rev_retate_stk(b, 's');
		c_++;
	}
	if (c_)
		call_inst_plus(c_v, a, b);
}

void	call_inst_(int c_v, t_list **a, t_list **b)
{
	if (c_v <= 3)
		call_inst_th(c_v, a, 'a');
	else if (c_v == 4)
		call_inst_fore(c_v, a, b);
	else if (c_v == 5)
		call_inst_five(c_v, a, b);
	else
		call_inst_plus(c_v, a, b);
}
