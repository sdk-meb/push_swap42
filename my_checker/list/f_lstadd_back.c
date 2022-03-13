/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:53:48 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/10 10:07:17 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next && p->next->next)
		p = p->next;
	new->prev = p;
	p = p->next;
	p->next = new;
}
