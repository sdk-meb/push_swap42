/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:53:31 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/03/14 12:40:23 by mes-sadk         ###   ########.fr       */
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
	iinst[i] = '\0';
	return (iinst);
}

void	check_do_inst(t_list **a, t_list **b, char *inst)
{
	if ((!(*inst) || !(*(inst + 1))) || (*inst != 'p' && *inst != 's' && *inst != 'r'))
		ft_error(NULL, NULL, NULL);
	if (*inst == 'p' && ((*(++inst) == 'a' && push_stk(b, a)) || (*inst == 'b' && push_stk(a, b)) || !(*(--inst))))
		inst++;
	else if (*inst == 's' && ((*(++inst) == 'a' && swap_stk(a)) || (*inst == 'b' && swap_stk(b)) || (*inst == 's' && swap_stk(b) && swap_stk(a)) || !(*(--inst))))
		inst++;
	else if (*inst == 'r')
	{
		if ((*(++inst) == 'a' && retate_stk(a)) || (*inst == 'b' && retate_stk(b)))
			inst++;
		else if ((*(inst + 1) == '\0' || *(inst + 1) == '\n') && ((*inst) == 'r' && retate_stk(a) && retate_stk (b)))
			inst++;
		else if ((*inst) == 'r' && ((*(++inst) == 'a' && rev_retate_stk(a)) || (*inst == 'b' && rev_retate_stk(b)) || ((*inst) == 'r' && rev_retate_stk(b) && rev_retate_stk(a))))
			inst++;
		else
			ft_error(NULL, NULL, NULL);
	}
	if (*inst == '\n' && *(++inst))
		check_do_inst(a, b, inst);
	else if (*inst)
		ft_error(NULL, NULL, NULL);
}

int	main(int count, char **stk)
{
	char	buff[1];
	t_list	**stk_a;
	t_list	**stk_b;

	check_dup_sort(stk_a = great_list(count, stk));
	if (read(0, buff, 1) <= 0)
	{
		ft_lstclear(stk_a);
		write(1, "KO\n", 3);
		return (0);
	}
	stk_b = malloc(sizeof(stk_b));
	*stk_b = NULL;
	*stk = NULL;
	*stk = ft_join(*stk, buff[0]);
	while (read(0, buff, 1) > 0)
		*stk = ft_join(*stk, buff[0]);
	ft_error(stk_a, stk_b, *stk);
	check_do_inst(stk_a, stk_b, *stk);
	check_sort(stk_a, stk_b);
	ft_lstclear(stk_a);
	ft_lstclear(stk_b);
	if (*stk)
		free (*stk);
	return (0);
}
