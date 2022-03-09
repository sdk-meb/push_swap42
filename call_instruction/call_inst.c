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
	int		val;

	p = *stk;
	while (p && p->next)
	{
		val = p->val;
		p = p->next;
		if ((order == 'c' && val > p->val)
			|| (order == 'd' && val < p->val))
			return (1);
	}
	return (0);
}

int	low_val(int x)
{
	static int t;

	if (x != -33)
		t = x;
	return (t);
}

int	high_val(int *lg_l)
{
	int a;
	int h_val;

	a = -1;
	h_val = -33;
	while (lg_l[++a] != -33)
	{
		if (lg_l[a] > h_val)
			h_val = lg_l[a];
	}
	return (h_val);
}

void	processing_the_ways(int **q, int r, int c_v)
{
	int	y[2];

	if ((*q)[1] != (*q)[3])
	{
		y[0] = c_v - r;
		y[1] = y[0] - (*q)[2] - (*q)[0];
		if ((*q)[1] == 1 && y[1] < y[0] / 2 && y[1] < (*q)[2] && y[1] >= 0)
		{
			(*q)[2] = y[1];
			(*q)[3] = (*q)[1];
		}
		else if ((*q)[1] == -1 && ((*q)[0] + (*q)[2]) > y[0] / 2 && y[0] - ((*q)[0] + (*q)[2]) < (*q)[2] && y[0] - ((*q)[0] + (*q)[2]) >= 0)
		{
			(*q)[2] = y[0] - ((*q)[0] + (*q)[2]);
			(*q)[3] = (*q)[1];
		}
	}
	if ((*q)[1] != (*q)[3])
	{
		y[1] = r - (*q)[0] - (*q)[2];
		if ((*q)[3] == 1 && y[1] < r / 2 && y[1] < (*q)[0] && y[1] >= 0)
		{
			(*q)[0] = y[1];
			(*q)[1] = (*q)[3];
		}
		else if ((*q)[3] == -1 && ((*q)[0] + (*q)[2]) > r / 2 && r - ((*q)[0] + (*q)[2]) < (*q)[0] && r - ((*q)[0] + (*q)[2]) >= 0)
		{
			(*q)[0] = r - ((*q)[0] + (*q)[2]);
			(*q)[1] = (*q)[3];
		}
	}
	if ((*q)[1] != (*q)[3])
	{
		if ((*q)[2] + (*q)[0] >= r)
		{
			(*q)[0] = r - (*q)[0];
			(*q)[3] = (*q)[1];
		}
		else if ((*q)[2] + (*q)[0] > c_v - r)
		{
			(*q)[2] = c_v - r - (*q)[2];
			(*q)[1] = (*q)[3];
		}
	}
		
}

void	do_inst(t_list	**a, t_list	**b, int *q)
{
	if (q[5] == q[7])
	{	
		while (q[5] == -1 && q[4] && q[6]-- && q[4]--)
		{
			rev_retate_stk(a, 'N');
			rev_retate_stk(b, 's');
		}
		while (q[5] == 1 && q[4]-- && q[6]--)
		{
			retate_stk(a, 'N');
			retate_stk(b, 's');
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
	push_stk(b, a,'a');
}

void	low_inst(t_list	**a, t_list	**b, int r, int c_v)
{
	int		*q;
	t_list	*sb;
	t_list	*sa;
	int		p[2];

	q = calloc(sizeof(int), 10);
	q[3] = 1;
	q[5] = 1;
	q[7] = 1;
	q[9] = -33;
	p[0] = 1;
	sb = *b;
	while (sb)
	{
		q[0] = 0;
		q[1] = 1;
		p[1] = 0;
		sa = *a;
		while (sa && ((sb->x_sort > sa->x_sort) || ((*a)->x_sort != low_val(-33) && !p[1])))
		{
			if (sb->x_sort > sa->x_sort)
				p[1] = 1;
			q[0]++;
			sa = sa->next;
		}
		if (q[0] > r / 2)
		{
			q[1] = -1;
			q[0] = r - q[0];
		}
		if (p[0] == 1 && q[2] > (c_v - r ) / 2)
		{
				q[3] = -1;
				p[0] = -1;
		}
		processing_the_ways(&q, r, c_v);
		printf("");
		if (q[9] == -33 || (q[1] != q[3] && q[0] + q[2] < q[9]) || (q[1] == q[3] && cmp_val(q[0], q[2], 'M' ) < q[9]))
		{
			q[4] = q[0];
			q[5] = q[1];
			q[6] = q[2];
			q[7] = q[3];
			q[9] = cmp_val(q[0], q[2], 'M');
			if (q[1] != q[3])
				q[9] = q[0] + q[2];
		}
		q[2] += p[0];
		sb = sb->next;
	}
//	do_inst(a, b, q);
	free(q);
//	if (*b)
//		low_inst(a, b, ++r, c_v);
}

int	lis(t_list **stk, int c_v)
{
	int		lg_l[c_v + 1];
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
		tv = tv->next;
	}
	int h_val = high_val(lg_l);
	v = (*stk)->prev;
	c_v = -33;
	while (c_v == -33 || v != (*stk)->prev)
	{
		if (lg_l[v->x_sort + 1] == h_val && (v->x_sort < c_v || c_v == -33))
		{
			v->vouch = 1;
			c_v = v->x_sort;
			if (h_val-- == 1)
				low_val(v->x_sort);
		}
		v = v->prev;
	}
	return (high_val(lg_l));
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

void	call_inst_dec(int c_v, t_list **b)
{
	static int	c_;

	if (!(*b))
		return ;
	if ((*b)->val < (*b)->next->val)
		swap_stk(b, 'a');
	else if (c_ < c_v)
	{
		retate_stk(b, 'a');
		c_++;
		call_inst_dec(c_v, b);
		return ;
	}
	if (!check_sort(b, 'd'))
	{
	//	while ((*a)->val > (*a)->prev->val)
	//		retate_stk(a, 'a');
		return ;
	}
	if (c_)
	{
			rev_retate_stk(b, 'a');
		c_--;
	}
	call_inst_dec(c_v, b);
}

void	call_inst_cro(int c_v, t_list **b)
{
	static int	c_;

	if (!(*b))
		return ;
	if ((*b)->val > (*b)->next->val)
		swap_stk(b, 'a');
	else if (c_ < c_v)
	{
		retate_stk(b, 'a');
		c_++;
		call_inst_cro(c_v, b);
		return ;
	}
	if (!check_sort(b, 'c'))
	{
	//	while ((*a)->val > (*a)->prev->val)
	//		retate_stk(a, 'a');
		return ;
	}
	if (c_)
	{
			rev_retate_stk(b, 'a');
		c_--;
	}
	call_inst_cro(c_v, b);
}

void	call_swap(t_list **a, t_list **b)
{
	if ((*a) && (*b) && (*a)->next && (*b)->next
		&& (*b)->val < (*b)->next->val && (*a)->val > (*a)->next->val)
		{
			swap_stk(a, 'N');
			swap_stk(b, 's');
		}
	else if ((*a) && (*a)->next && (*a)->val > (*a)->next->val)
		swap_stk(a, 'a');
	else if ((*b) && (*b)->next && (*b)->val < (*b)->next->val)
		swap_stk(b, 'b');
}

void	call_inst_(int c_v, t_list **a, t_list **b)
{
	int	range[4];
	int	d;
	int r;

	if (c_v <= 3)
		call_inst_th(c_v, a, 'a');
	else if (c_v == 4)
		call_inst_fore(c_v, a, b);
	else if (c_v == 5)
		call_inst_five(c_v, a, b);
	else if(c_v <= 100)
	{ 
		r = lis(a, c_v);
		range[0] = (c_v / 4) - 1;
 		range[1] = (c_v / 4) * 2 - 2;
 		range[2] = (c_v / 4) * 2 - 1;
		range[3] = (c_v / 4) * 3 - 2;
		while (range[1] >= -1)
		{
			d = (c_v / 4) * 2;
			while (d > 0)
			{
				while ((*a) && (*a)->x_sort >= range[2] && (*a)->x_sort <= range[3])
				{
					if (!(*a)->vouch)
						push_stk(a, b, 'b');
					else
						retate_stk(a, 'a');
					d--;
				}
				while ((*a) && (*a)->x_sort >= range[0] && (*a)->x_sort <= range[1])
				{
					if (!(*a)->vouch)
					{		
						push_stk(a, b, 'b');
						retate_stk(b, 'b');
					}
					else
						retate_stk(a, 'a');
					d--;
				}
				if (d && (*a) && ((*a)->x_sort < range[0] || (*a)->x_sort > range[3] || (*a)->vouch))
					retate_stk(a, 'a');
			}
			range[1] = range[0] - 1;
			range[0] = -1;
			range[2] = range[3] + 1;
			range[3] = c_v - 2;
		}
	// 	t_list *q = *a;
	// while (q)
	// {
	// 	printf("%d______%d___%d\n", q->vouch,q->x_sort,q->val );
	// 	q = q->next;
	// }
	// q = *b;
	// while (q)
	// {
	// 	printf("%d______%d___%d\n", q->vouch,q->x_sort,q->val );
	// 	q = q->next;
	// }
		low_inst(a, b, r, c_v);
	}
}
