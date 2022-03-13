/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:52:54 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/13 14:52:57 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	ft_error(t_list **stk)
{
	ft_lstclear(stk);
	write (1, "error", 5);
	exit (-1);
}

int	check_sort(t_list **stk)
{
	t_list	*p;

	p = *stk;
	while (p && p->next)
	{
		if (p->next->val < p->val)
			return (1);
		p = p->next;
	}
	return (0);
}

void	check_dup_sort(t_list	**stk)
{
	t_list		*node;
	t_list		*nod;
	int			val[2];

	nod = *stk;
	while (nod)
	{
		val[0] = nod->val;
		node = nod->next;
		while (node)
		{
			if (val[0] == node->val)
				ft_error(stk);
			node = node->next;
		}
		nod = nod->next;
	}
}
