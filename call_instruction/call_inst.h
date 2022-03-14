/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_inst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:57:56 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/14 12:17:06 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     CALL_INST_H
# define    CALL_INST_H

# include "../sorted.h"

void	call_inst_(int c_v, t_list **a, t_list **b);
int		three_fore(t_list **a);
int		check_sort(t_list **stk, char order);

#endif
