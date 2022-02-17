/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:58:30 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/13 15:21:22 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sorted.h"

int	check_dup_sort(t_list	**stk)
{
	t_list		*node;
	t_list		*nod;
	int			val[2];

	nod = *stk;
	val[1] = 0;
	while (nod)
	{
		val[0] = nod->val;
		node = nod->next;
		while (node)
		{
			if (val[0] == node->val)
			{
				ft_lstclear(stk);
				write (1, "error", 5);
				exit (-1);
			}
			if (val[0] > node->val)
				val[1] = 1;
			node = node->next;
		}
		nod = nod->next;
	}
	return (val[1]);
}

void	algo_sorted(int count_val, t_list **stk_a)
{
	t_list	**stk_b;
	int		c;

	c = count_val / 2;
	if (count_val <= 3)
		call_inst_th(count_val, stk_a, 'a');
	else
	{
		stk_b = (t_list **)malloc(sizeof(stk_b));
		*stk_b = NULL;
		//if (count_val <= 5)
		//	call_inst_five(count_val, stk_a, stk_b);
		//else
		//	all_sort(stk_a, stk_b, count_val);
		ft_lstclear(stk_b);
	}
}

t_list	**great_list(int count, char **stk)
{
	t_list		**lst;

	if (count <= 1)
	{
		write (1, "error", 5);
		exit (-1);
	}
	lst = (t_list **)malloc(sizeof(lst));
	if (!lst)
		exit (-1);
	*lst = NULL;
	while (--count)
		ft_lstadd_front(lst, ft_lstnew(ft_atoi(lst, stk[count])));
	return (lst);
}

int	main(int count, char **stk)
{
	t_list	**stack_a;
	t_list	*q;

	stack_a = great_list(count, stk);
	if (check_dup_sort(stack_a))
		algo_sorted(count - 1, stack_a);
	q = *stack_a;
	while (q)
	{
		printf("%d\n", q->val);
		q = q->next;
	}
	ft_lstclear(stack_a);
	return (0);
}
