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
#include "checker.h"

/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*                 ---      ---       ---                    */
/*      			SA   +   SB    =   SS                    */
/*                      ___       ___                        */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

int	swap_stk(t_list **stk)
{
	int		swap_val;

	if (!*stk || !(*stk)->next)
		return (1);
	swap_val = (*stk)->val;
	(*stk)->val = (*stk)->next->val;
	(*stk)->next->val = swap_val;
	return (1);
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*                           -  -                            */
/*                  PUSH_A    OR    PUSH_B                   */
/*                         ___   ___                         */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

int	push_stk(t_list **stk, t_list **stk_to)
{
	t_list	*node;

	if (!*stk)
		return (1);
	node = *stk;
	*stk = (*stk)->next;
	if (*stk)
		(*stk)->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	ft_lstadd_front(stk_to, node);
	return (1);
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*                  ----      ----       ----                */
/*      			RR_B  +   RR_A   =   RR_R                */
/*                       ___        ___                      */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

int	rev_retate_stk(t_list	**stk)
{
	t_list	*node;

	if (!*stk || !(*stk)->next)
		return (1);
	node = *stk;
	node->prev->next = *stk;
	node->prev->prev->next = NULL;
	*stk = node->prev;
	return (1);
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*					----       ----        ----              */
/*					R_A   +    R_B    =	   R_R               */
/*                        ___         ___                    */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

int	retate_stk(t_list **stk)
{
	t_list	*node;
	t_list	*sk;

	if (!*stk || !(*stk)->next)
		return (1);
	sk = *stk;
	node = sk->prev;
	node->next = sk;
	*stk = sk->next;
	sk->next = NULL;
	return (1);
}
