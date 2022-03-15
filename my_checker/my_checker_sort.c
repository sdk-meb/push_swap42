/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:53:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/14 12:40:23 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	check_do_inst(t_list **a, t_list **b, char *inst)
{
	if (*inst == 'p' && ((*(++inst) == 'a' && push_stk(b, a))
		|| (*inst == 'b' && push_stk(a, b)) || !(*(--inst))))
			inst++;
	else if (*inst == 's' && ((*(++inst) == 'a' && swap_stk(a)) || (*inst == 'b' && swap_stk(b))
		|| (*inst == 's' && swap_stk(b) && swap_stk(a)) || !(*(--inst))))
			inst++;
	else if(*inst == 'r')
	{
		if ((*(++inst) == 'a' && retate_stk(a)) || (*inst == 'b' && retate_stk(b)))
				inst++;
		else if ((*(inst + 1) == '\0' || *(inst + 1) == '\n')
			&& ((*inst) == 'r' && retate_stk(a) && retate_stk (b)))
				inst++;
		else if ((*inst) == 'r' && ((*(++inst) == 'a' && rev_retate_stk(a))
			|| (*inst == 'b' && rev_retate_stk(b))
			|| ((*inst) == 'r'&& rev_retate_stk(b) && rev_retate_stk(a))))
				inst++;
	}
}

int	logic_inst(t_list **a, t_list **b, char *inst)
{
	if (((inst[0] == 'p' && (inst[1] == 'a' || inst[1] == 'b'))
		|| (inst[0] == 's' && (inst[1] == 'a' || inst[1] == 'b' || inst[1] == 's')))
		&& (inst[2] == '\n' || inst[2] == '\0'))
			return (1);
	if (inst[0] == 'r' && (inst[1] == 'a' || inst[1] == 'b' || inst[1] == 'r')
		&& (inst[2] == '\n' || inst[2] == '\0'))
			return (1);
	if (inst[0] == 'r' && inst[1] == 'r' && (inst[2] == 'a' || inst[2] == 'b' || inst[2] == 'r'))
	{
		read(0, "", 1);;;;;-<>
			return (1);
	}
	ft_error(a, b);
	return (0);
}

int	main(int count, char **stk)
{
	char	inst[4];
	int		r;
	t_list	**stk_a;
	t_list	**stk_b;

	if (count <= 1)
		exit (0);
	check_dup_sort(stk_a = great_list(count, stk));
	stk_b = malloc(sizeof(stk_b));
	*stk_b = NULL;
	while ()
	{
	}
	check_sort(stk_a, stk_b);
	ft_lstclear(stk_a);
	ft_lstclear(stk_b);
	return (0);
}
