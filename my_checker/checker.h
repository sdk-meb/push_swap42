/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:53:15 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/13 14:53:19 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H 
# define CHECKER_H

# include "list/list.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
# include <stdbool.h>
#include <stdlib.h>
typedef struct integer {
	int	i;
	int	j;
	int	n;
}t_intgr;

void	ft_error(t_list **stk);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	ft_strlen(char *s);
void     check_dup_sort(t_list	**stk);
char	**ft_split(char *s, char c, int *count);
int		ft_atoi(t_list **lstclr, char *str);
int	check_sort(t_list **stk);
void	swap_stk(t_list **stk);
void	push_stk(t_list **stk, t_list **stk_to);
void	retate_stk(t_list **stk);
void	rev_retate_stk(t_list	**stk);
t_list	**great_list(int count, char **stk);

#endif
