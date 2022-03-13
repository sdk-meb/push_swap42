/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:02:23 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/10 10:11:19 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

t_list	*ft_lstnew(int num)
{
	t_list	*node;

	node = (t_list *)calloc (sizeof(*node), 1);
	if (!node)
		return (NULL);
	node->val = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
