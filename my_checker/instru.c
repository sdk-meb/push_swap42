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

void	swap_stk(t_list **stk)
{
	int		swap_val;

	if (!*stk)
		return ;
	if ((*stk)->next == NULL)
		return ;
	swap_val = (*stk)->val;
	(*stk)->val = (*stk)->next->val;
	(*stk)->next->val = swap_val;
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*                           -  -                            */
/*                  PUSH_A    OR    PUSH_B                   */
/*                         ___   ___                         */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

void	push_stk(t_list **stk, t_list **stk_to)
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
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*                  ----      ----       ----                */
/*      			RR_B  +   RR_A   =   RR_R                */
/*                       ___        ___                      */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

void	rev_retate_stk(t_list	**stk)
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
}
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*					----       ----        ----              */
/*					R_A   +    R_B    =	   R_R               */
/*                        ___         ___                    */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

void	retate_stk(t_list **stk)
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
}
