/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:53:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/13 14:53:33 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	count = count * size;
	p = malloc(count);
	if (!p)
		return (NULL);
	while (count--)
		p[count] = 0;
	return ((void *)p);
}

char	*ft_join(char *inst, char buff)
{
	int		i;
	char	*iinst;

	i = ft_strlen(inst) + 1;
	iinst = ft_calloc (i + 1, 1);
	if (!iinst)
		return (NULL);
	ft_memcpy(iinst, inst, i - 1);
	free (inst);
	iinst[i - 1] = buff;
	return (iinst);
}

void	check_inst(char *inst, t_list **stk)
{
	while (*inst && *(inst + 1))
	{
		if (*inst == 'p' && (*(++inst) == 'a' || *inst == 'b' || !(*(--inst))))
			inst++;
		else if (*inst == 's' && (*(++inst) == 'a' || *inst == 'b' ||  *inst == 's' || !(*(--inst))))
			inst++;
		else if (*inst == 'r')
		{
			if (*(++inst) == 'a' || *inst == 'b')
				inst++;
			else if ((*(inst + 1) == '\0' || *(inst + 1) == '\n') && *(inst) == 'r')
				inst++;
			else if (*(inst) == 'r' && (*(++inst) == 'a'|| *inst == 'b' || *(inst) == 'r'))
				inst++;
			else
				break;
		}
		else
			break;
		if (*inst)
			inst++;
	}
	printf("\n\n________________________________________\n");
	if (*inst)
		ft_error(stk);
	
}

void	do_inst_checker(t_list **stk_a, t_list **stk_b, char *inst)
{
	if (*inst == 'r' && (*(inst + 2) == '\n' || *(inst + 3) == '\0'))
	{
		if (*(++inst) == 'a' || (*inst == 'r' && *(inst + 1) != 'r'))
			retate_stk(stk_a);
		if (*inst == 'b' || (*inst == 'r' && *(inst + 1) != 'r'))
			retate_stk(stk_b);
	}
	else if (*inst == 'r' && *inst++)
	{
		if (*(++inst) == 'a' || *inst == 'r')
			rev_retate_stk(stk_a);
		if (*inst == 'b' || *inst == 'r')
			rev_retate_stk(stk_b);
	}
	if (*inst == 's')
	{
		if (*(++inst) == 'a' || *inst == 's')
			swap_stk(stk_a);
		if (*inst == 'b' || *inst == 's')
			swap_stk(stk_b);
		inst++;
	}
	if (*inst == 'p')
	{
		if (*(++inst) == 'b')
			push_stk(stk_a, stk_b);
		else if (*inst == 'a')
			push_stk(stk_b, stk_a);
		inst++;
	}
	if (*inst != '\n' || *inst == '\0')
		return ;
	do_inst_checker(stk_a, stk_b, inst++);
}

int	main(int count, char **stk)
{
	char	buff[1];
	char	*inst;
	t_list	**stk_a;
	t_list	**stk_b;
	t_list	*q;

	inst = NULL;
	while (read(0, buff, 1) > 0)
		inst = ft_join(inst, buff[0]);
	stk_a = great_list(count, stk);
	check_inst(inst, stk_a);
	stk_b = malloc(sizeof(stk_b));
	do_inst_checker(stk_a, stk_b, inst);
	q = *stk_a;
	while (q)
	{
		printf("___%d______\n",q->val);
		q = q->next;
	}
	ft_lstclear(stk_a);
	free(stk_b);
	if (inst)
		free (inst);
	return (0);
}
