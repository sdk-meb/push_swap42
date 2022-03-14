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

void	ft_error(t_list **stk_a, t_list **stk_b, char *inst)
{
	static t_list	**a;
	static t_list	**b;
	static char		*ins;

	if (a && b && !stk_a && !stk_b)
	{
		ft_lstclear(a);
		ft_lstclear(b);
		free(inst);
		write (1, "error", 5);
		exit (1);
	}
	ins = inst;
	a = stk_a;
	b = stk_b;
}

void	check_sort(t_list **stk, t_list **b)
{
	t_list	*p;

	p = *stk;
	if (*b)
	{
		write(1, "KO", 2);
		return ;
	}
	while (p && p->next)
	{
		if (p->next->val < p->val)
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
	char		*p;

	p = "OK";
	no = *stk;
	while (no->next)
	{
		ne = no->next;
		while (ne)
		{
			if (p[0] == 'O' && no->val > ne->val)
				p = "no_sorted";
			if (no->val == ne->val)
				p = "error";
			ne = ne->next;
		}
		no = no->next;
	}
	if (p[0] == 'n')
		return ;
	write(1, p, ft_strlen(p));
	ft_lstclear(stk);
	exit (0);
}
