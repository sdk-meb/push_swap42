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

void	ft_error(t_list **stk)
{
	ft_lstclear(stk);
	write (1, "error", 5);
	exit (-1);
}

int	check_dup_sort(t_list	**stk)
{
	t_list		*node;
	t_list		*nod;
	int			val[2];

	nod = *stk;
	val[1] = -33;
	while (nod)
	{
		val[0] = nod->val;
		node = nod->next;
		while (node)
		{
			if (val[0] == node->val)
				ft_error(stk);
			if (val[0] > node->val)
				val[1] = nod->x_sort++;
			else
				++(node->x_sort);
			node = node->next;
		}
		nod = nod->next;
	}
	return (val[1]);
}

void	algo_sorted(int count_val, t_list **stk_a)
{
	t_list	**stk_b;

	stk_b = (t_list **)malloc(sizeof(stk_b));
	if (!stk_b)
		return ;
	*stk_b = NULL;
	call_inst_(count_val, stk_a, stk_b);
	ft_lstclear(stk_b);
}

t_list	**great_list(int count, char **stk)
{
	t_list		**lst;

	if (count <= 1)
	{
		write (1, "error", 5);
		exit (-1);
	}
	// if (stk[1][0] == '\"')
	// 	stk = ft_split(stk);
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
	int i = -1;

	stack_a = great_list(count, stk);
	if (check_dup_sort(stack_a) != -33)
		algo_sorted(count - 1, stack_a);
	q = *stack_a;
	while (q)
	{
		printf("___%d______\n",q->x_sort - (i++)  );
		q = q->next;
	}
	ft_lstclear(stack_a);
	return (0);
}
