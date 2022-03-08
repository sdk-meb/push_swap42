/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:58:51 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/11 17:51:35 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sorted.h"

/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*                 ---      ---       ---                    */
/*      			SA   +   SB    =   SS                    */
/*                      ___       ___                        */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

void	swap_stk(t_list **stk, char name_stk)
{
	int		swap_val;

	if (!*stk)
		return ;
	if ((*stk)->next == NULL)
		return ;
	swap_val = (*stk)->val;
	(*stk)->val = (*stk)->next->val;
	(*stk)->next->val = swap_val;
	swap_val = (*stk)->x_sort;
	(*stk)->x_sort = (*stk)->next->x_sort;
	(*stk)->next->x_sort = swap_val;
	if (name_stk != 'N')
	{
		write(1, "s", 1);
		write(1, &name_stk, 1);
		write(1, "\n", 1);
	}
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*                           -  -                            */
/*                  PUSH_A    OR    PUSH_B                   */
/*                         ___   ___                         */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

void	push_stk(t_list **stk, t_list **stk_to, char c)
{
	t_list	*node;

	if (!*stk)
		return ;
	node = *stk;
	*stk = (*stk)->next;
	if (*stk)
		(*stk)->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	ft_lstadd_front(stk_to, node);
	if (c == 'a')
		write (1, "pa\n", 3);
	else if (c == 'b')
		write (1, "pb\n", 3);
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*                  ----      ----       ----                */
/*      			RR_B  +   RR_A   =   RR_R                */
/*                       ___        ___                      */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

void	rev_retate_stk(t_list	**stk, char name_stk)
{
	t_list	*node;

	if (!*stk)
		return ;
	if ((*stk)->next == NULL)
		return ;
	node = *stk;
	node->prev->next = *stk;
	node->prev->prev->next = NULL;
	*stk = node->prev;
	if (name_stk != 'N')
	{
		write(1, "rr", 2);
		write(1, &name_stk, 1);
		write(1, "\n", 1);
	}
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*					----       ----        ----              */
/*					R_A   +    R_B    =	   R_R               */
/*                        ___         ___                    */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

void	retate_stk(t_list **stk, char name_stk)
{
	t_list	*node;
	t_list	*sk;

	if (!*stk)
		return ;
	if ((*stk)->next == NULL)
		return ;
	sk = *stk;
	node = sk->prev;
	node->next = sk;
	*stk = sk->next;
	sk->next = NULL;
	if (name_stk != 'N')
	{
		write(1, "r", 1);
		write(1, &name_stk, 1);
		write(1, "\n", 1);
	}
}
