#include "aux.h"


/*void    random_val(int *val)
{
    char    f[val[0] + 1];
    static int b;
    while (val[0])
    {
        b = val[0] + val[1] - val[0]/3 + b / 4;
        if (b < val[2] && b > val[1] && f[b] != 'n')
        {
            printf("%d  ",b);
            f[b] = 'n';
            val[0]--;
        }   
    }
}

int main()
{
    int r[3];
    char  s[]="\0\0\0\0\0\0\0\0\0\0";
    int     val[3];
    write(1, "count values ??  ", 17);
    r[0] = read (1, s, 10);
    val[0] = atoi(s);
    write(1, "min value ??  ", 15);
    r[1] = read (1, s, 10);
    val[1] = atoi(s);
    write(1, "max value ??  ", 15);
    r[2] = read (1, s, 10);
    val[2] = atoi(s);
    random_val(val);
}*/

/*
void	call_swap(t_list **a, t_list **b)
{
	if ((*a) && (*b) && (*a)->next && (*b)->next
		&& (*b)->val < (*b)->next->val && (*a)->val > (*a)->next->val)
		{
			swap_stk(a, 'N');
			swap_stk(b, 's');
		}
	else if ((*a) && (*a)->next && (*a)->val > (*a)->next->val)
		swap_stk(a, 'a');
	else if ((*b) && (*b)->next && (*b)->val < (*b)->next->val)
		swap_stk(b, 'b');
}
	int	range[4];
range[0] = (c_v / 4) - 1;
 		range[1] = (c_v / 4) * 2 - 2;
 		range[2] = (c_v / 4) * 2 - 1;
		range[3] = (c_v / 4) * 3 - 2;
		while (range[1] >= -1)
		{
			d = (c_v / 4) * 2;
			while (d > 0)
			{
				while ((*a) && (*a)->x_sort >= range[2] && (*a)->x_sort <= range[3])
				{
					if (!(*a)->vouch)
						push_stk(a, b, 'b');
					else
						retate_stk(a, 'a');
					d--;
				}
				while ((*a) && (*a)->x_sort >= range[0] && (*a)->x_sort <= range[1])
				{
					if (!(*a)->vouch)
					{		
						push_stk(a, b, 'b');
						retate_stk(b, 'b');
					}
					else
						retate_stk(a, 'a');
					d--;
				}
				if (d && (*a) && ((*a)->x_sort < range[0] || (*a)->x_sort > range[3] || (*a)->vouch))
					retate_stk(a, 'a');
			}
			range[1] = range[0] - 1;
			range[0] = -1;
			range[2] = range[3] + 1;
			range[3] = c_v - 2;
		}
		t_list *q = *a;
	while (q)
	{
		printf("%d______%d___%d\n", q->vouch,q->x_sort,q->val );
		q = q->next;
	}
	q = *b;
	while (q)
	{
		printf("%d______%d___%d\n", q->vouch,q->x_sort,q->val );
		q = q->next;
	}	
void	call_inst_dec(int c_v, t_list **b)
{
	static int	c_;
	if (!(*b))
		return ;
	if ((*b)->val < (*b)->next->val)
		swap_stk(b, 'a');
	else if (c_ < c_v)
	{
		retate_stk(b, 'a');
		c_++;
		call_inst_dec(c_v, b);
		return ;
	}
	if (!check_sort(b, 'd'))
	{
		while ((*a)->val > (*a)->prev->val)
			retate_stk(a, 'a');
		return ;
	}
	if (c_)
	{
			rev_retate_stk(b, 'a');
		c_--;
	}
	call_inst_dec(c_v, b);
}
void	call_inst_cro(int c_v, t_list **b)
{
	static int	c_;
	if (!(*b))
		return ;
	if ((*b)->val > (*b)->next->val)
		swap_stk(b, 'a');
	else if (c_ < c_v)
	{
		retate_stk(b, 'a');
		c_++;
		call_inst_cro(c_v, b);
		return ;
	}
	if (!check_sort(b, 'c'))
	{
		while ((*a)->val > (*a)->prev->val)
			retate_stk(a, 'a');
		return ;
	}
	if (c_)
	{
			rev_retate_stk(b, 'a');
		c_--;
	}
	call_inst_cro(c_v, b);
}*/

// void	processing_the_ways(int **q, int r, int c_v)
// 	if (!(*q)[0] || !(*q)[2])
// 		return ;
	// if ((*q)[1] != (*q)[3])
	// {
	// 	y[0] = (*q)[0] + (*q)[2];
	// 	if ()
	// }
	// {
	// 	y[0] = c_v - r;
	// 	y[1] = y[0] - (*q)[2] - (*q)[0];
	// 	if ((*q)[1] == 1 && y[1] < y[0] / 2 && y[1] < (*q)[2] && y[1] >= 0)
	// 	{
	// 		(*q)[2] = y[1];
	// 		(*q)[3] = (*q)[1];
	// 	}
	// 	else if ((*q)[1] == -1 && ((*q)[0] + (*q)[2]) > y[0] / 2 && y[0] - ((*q)[0] + (*q)[2]) < (*q)[2] && y[0] - ((*q)[0] + (*q)[2]) >= 0)
	// 	{
	// 		(*q)[2] = y[0] - ((*q)[0] + (*q)[2]);
	// 		(*q)[3] = (*q)[1];
	// 	}
	// }
	// if ((*q)[1] != (*q)[3])
	// {
	// 	y[1] = r - (*q)[0] - (*q)[2];
	// 	if ((*q)[3] == 1 && y[1] < r / 2 && y[1] < (*q)[0] && y[1] >= 0)
	// 	{
	// 		(*q)[0] = y[1];
	// 		(*q)[1] = (*q)[3];
	// 	}
	// 	else if ((*q)[3] == -1 && ((*q)[0] + (*q)[2]) > r / 2 && r - ((*q)[0] + (*q)[2]) < (*q)[0] && r - ((*q)[0] + (*q)[2]) >= 0)
	// 	{
	// 		(*q)[0] = r - ((*q)[0] + (*q)[2]);
	// 		(*q)[1] = (*q)[3];
	// 	}
	// }
	// if ((*q)[1] != (*q)[3])
	// {
	// 	if ((*q)[2] + (*q)[0] >= r)
	// 	{
	// 		(*q)[0] = r - (*q)[0];
	// 		(*q)[3] = (*q)[1];
	// 	}
	// 	else if ((*q)[2] + (*q)[0] > c_v - r)
	// 	{
	// 		(*q)[2] = c_v - r - (*q)[2];
	// 		(*q)[1] = (*q)[3];
	// 	}
	// }		
//}

