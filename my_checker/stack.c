/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:53:41 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/13 14:53:45 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

t_list	**great_list(int count, char **stk)
{
	t_list		**lst;

	if (count <= 1)
	{
		write (1, "error", 5);
		exit (-1);
	}
	lst = (t_list **)malloc(sizeof(lst));
	if (!lst)
		exit (-1);
	*lst = NULL;
	if (count == 2)
	{
		stk = ft_split(stk[1], ' ', &count);
		while (count-- > 0)
		{
			ft_lstadd_front(lst, ft_lstnew(ft_atoi(lst, stk[count])));
			free(stk[count]);
		}
		free (stk);
	}
	while (--count > 0)
		ft_lstadd_front(lst, ft_lstnew(ft_atoi(lst, stk[count])));
	return (lst);
}
