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

void	ft_error(t_list **stk_a, t_list **stk_b)
{
	ft_lstclear(stk_a);
	ft_lstclear(stk_b);
	write (1, "Error", 5);
	exit (1);
}

void	check_sort(t_list **stk, t_list **b)
{
	t_list	*p;

	p = *stk;
	while (*b || (p && p->next ))
	{
		if (*b || p->next->val < p->val)
		{
			write(1, "KO", 2);
			return ;
		}
		p = p->next;
	}
	write(1, "OK", 2);
}

void	check_dup_sort(t_list	**stk)
{
	t_list		*ne;
	t_list		*no;

	no = *stk;
	while (no->next)
	{
		ne = no->next;
		while (ne)
		{
			if (no->val == ne->val)
			{
				write(1, "ERROR", 5);
				ft_lstclear(stk);
				exit (1);
			}
			ne = ne->next;
		}
		no = no->next;
	}
}
