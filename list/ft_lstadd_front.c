/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:09:38 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/10 14:17:35 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../sorted.h"
//node(new) add to list in the header

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(lst && new))
	{
		ft_lstclear(lst);
		exit (-1);
	}
	if (!*lst)
	{	
		*lst = new;
		new->prev = new;
		return ;
	}
	new->prev = (*lst)->prev;
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}
