/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:00:13 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/02/10 10:11:34 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdbool.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				val;
	bool			vouch;
	int				x_sort;
	struct s_list	*next;
}							t_list;

t_list	*ft_lstnew(int num);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list **lst);
void	ft_lstclear(t_list **lst);

#endif
