/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:31:35 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/14 12:39:03 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include "list/list.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct integer{
	int	i;
	int	j;
	int	n;
}t_intgr;

void	ft_error(t_list **stk_a, t_list **stk_b);
void	check_dup_sort(t_list **stk);
void	check_sort(t_list **stk, t_list **b);
char	**ft_split(char *s, char c, int *count);
int		swap_stk(t_list **stk);
int		push_stk(t_list **stk, t_list **stk_to);
int		retate_stk(t_list **stk);
int		rev_retate_stk(t_list **stk);
int		ft_strlen(char *s);
int		ft_atoi(t_list **lstclr, char *str);
t_list	**great_list(int count, char **stk);

#endif
