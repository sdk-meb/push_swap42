/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_for_th.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:57:40 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/27 00:52:00 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "call_inst.h"

int	check_sort(t_list **stk, char order)
{
	t_list	*p;

	p = *stk;
	while (p && p->next)
	{
		if ((order == 'c' && p->next->val < p->val)
			^ (order == 'd' && p->next->val > p->val))
			return (1);
		p = p->next;
	}
	return (0);
}

void	do_inst(t_list	**a, t_list	**b, int *q)
{
	if (q[5] == q[7])
	{
		while (q[5] == -1 && q[4] > 0 && q[6] > 0 && q[4]-- && q[6]--)
		{
			rev_retate_stk(a, 's');
			rev_retate_stk(b, 'N');
		}
		while (q[5] == 1 && q[4] > 0 && q[6] > 0 && q[4]-- && q[6]--)
		{
			retate_stk(a, 's');
			retate_stk(b, 'N');
		}
	}
	while (q[5] == 1 && q[4]-- > 0)
		retate_stk(a, 'a');
	while (q[5] == -1 && q[4]-- > 0)
		rev_retate_stk(a, 'a');
	while (q[7] == 1 && q[6]-- > 0)
		retate_stk(b, 'b');
	while (q[7] == -1 && q[6]-- > 0)
		rev_retate_stk(b, 'b');
	push_stk(b, a, 'a');
	low_val((*a)->x_sort, 0);
	high_val((*a)->x_sort, 0);
}

void	low_inst(t_list	**a, t_list	**b, int r, int c_v)
{
	int		*q;
	t_list	*sb;
	t_list	*sa;
	int		p[2];

	q = calloc(sizeof(int), 9);
	q[3] = 1;
	q[5] = 1;
	q[7] = 1;
	q[8] = -33;
	p[0] = 1;
	sb = *b;
	while (sb)
	{
		q[0] = 0;
		q[1] = 1;
		p[1] = 0;
		sa = *a;
		while (sa)
		{
			if (!sa || (sb->val < sa->val && sa->x_sort == low_val(-33, 0))
				|| (sb->val > sa->prev->val && sa->prev->x_sort == high_val(-33, 0))
				|| (sb->val < sa->val && sb->val > sa->prev->val))
				break ;
			q[0]++;
			sa = sa->next;
		}
		if (q[0] >= (r + 1) / 2)
		{
			q[1] = -1;
			q[0] = r - q[0];
		}
		if (q[8] == -33 || (q[1] != q[3] && q[0] + q[2] < q[8]) || (q[1] == q[3] && cmp_val(q[0], q[2], 'M' ) < q[8]))
		{
			q[4] = q[0];
			q[5] = q[1];
			q[6] = q[2];
			q[7] = q[3];
			q[8] = cmp_val(q[0], q[2], 'M');
			if (q[1] != q[3])
				q[8] = q[0] + q[2];
		}
		q[2] += p[0];
		if (q[3] == 1 && q[2] >= (c_v - r + 1) / 2)
		{
				q[3] = c_v - r;
				if (evan_odd(&q[3], 'O', 0) == 'O')
					q[2] -= 1;
				p[0] = -1;
				q[3] = -1;
		}
		sb = sb->next;
	}
	do_inst(a, b, q);
	free(q);
	if (*b)
		low_inst(a, b, ++r, c_v);
}

void	lis(t_list **stk, int c_v)
{
	int		lg_l[c_v + 1];
	int 	h_val;
	t_list	*tv;
	t_list	*v;

	lg_l [c_v] = -33;
	while (c_v--)
		lg_l[c_v] = 1;
	tv = *stk;
	while (tv)
	{
		v = *stk;
		while (v != tv)
		{
			if (tv->x_sort > v->x_sort && lg_l[v->x_sort + 1] + 1 > lg_l[tv->x_sort + 1])
				lg_l[tv->x_sort + 1] = lg_l[v->x_sort + 1] + 1;
			v = v->next;	
		}
		h_val = high_val(lg_l[tv->x_sort + 1], 0);
		tv = tv->next;
	}
	v = (*stk)->prev;
	c_v = -33;
	while (c_v == -33 || v != (*stk)->prev)
	{
		if (lg_l[v->x_sort + 1] == h_val && (v->x_sort < c_v || c_v == -33))
		{
			v->vouch = 1;
			c_v = v->x_sort;
			h_val--;
		}
		v = v->prev;
	}
}

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

int	rev_or_re(t_list **stk, int x_, int c_v)
{
	t_list	*p;
	int		track;

	track = 0;
	p = *stk;
	while (p)
	{
		if (p->x_sort == x_)
			break ;
		track++;
		p = p->next;
	}
	if (track <= c_v / 2)
		return (track);
	return (track - c_v);
}

void	call_inst_fore(int c_v, t_list **a, t_list **b)
{
	int	track;

	track = rev_or_re(a, -1, c_v);
	while (track > 0 && (*a)->x_sort != -1)
		retate_stk(a, 'a');
	while (track < 0 && (*a)->x_sort != -1)
		rev_retate_stk(a, 'a');
	push_stk(a, b, 'b');
	call_inst_th(3, a, 'a');
	push_stk(b, a, 'a');
}

void	call_inst_five(int c_v, t_list **a, t_list **b)
{
	int	track;
	int	neded;

	neded = 0;
	track = rev_or_re(a, -1, c_v);
	while (track && (*a)->x_sort != -1)
	{
		if (((*a)->x_sort == 0 || (*a)->x_sort == 3) && !(neded++))
			push_stk (a, b, 'b');
		else if (track > 0)
			retate_stk(a, 'a');
		else if (track < 0)
			rev_retate_stk(a, 'a');
	}
	push_stk (a, b, 'b');
	if (!neded)
	{
		if ((*a)->next->x_sort == 3 || (*a)->next->x_sort == 0)
			retate_stk(a, 'a');
		else if ((*a)->prev->x_sort == 3 || (*a)->prev->x_sort == 0)
			rev_retate_stk(a, 'a');
		push_stk(a, b, 'b');
	}
	call_inst_th(3, a, 'a');
	if (((*b)->x_sort == 0 || (*b)->next->x_sort == 0)
		&& (*b)->next->x_sort > (*b)->x_sort)
		swap_stk (b, 'b');
	push_stk(b, a, 'a');
	if ((*a)->x_sort > (*a)->prev->x_sort)
		retate_stk (a, 'a');
	push_stk(b, a, 'a');
}

void	call_inst_(int c_v, t_list **a, t_list **b)
{
	int	d;
	int	r;

	r = 0;
	if (c_v <= 3)
		call_inst_th(c_v, a, 'a');
	else if (c_v == 4)
		call_inst_fore(c_v, a, b);
	else if (c_v == 5)
		call_inst_five(c_v, a, b);
	else
	{
		lis(a, c_v);
		d = c_v;
		while (d--)
		{
			if (!(*a)->vouch)
				push_stk(a, b, 'b');
			else if(++r)
				retate_stk(a, 'a');
		}
		low_val((*a)->x_sort, 1);
		high_val((*a)->prev->x_sort, 1);
		low_inst(a, b, r, c_v);
		c_v = rev_or_re(a, -1, c_v);
		while ((*a)->x_sort != -1)
			retate_stk(a, 'a');
	}
}
