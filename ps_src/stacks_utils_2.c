/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap                                            :+:      :+:* :+: * */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 19:00:00 by hriser            #+#    #+#             */
/*   Updated: 1970/01/01 19:00:00 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexed_array(t_stack stack, int *num)
{
	int	i;

	i = -1;
	while (++i < stack.len)
		num[i] = stack.stack[i].index;
	return (*num);
}

int	isnear(t_stack stack, int med)
{
	int		i;
	int		z;
	int		*num;

	i = stack.len - 1;
	num = malloc(sizeof(int) * (i + 1));
	if (!num)
		return (0);
	*num = indexed_array(stack, num);
	z = i;
	while (num[i] != med)
		i--;
	z = z - i;
	i = 0;
	while (num[i] != med)
		i++;
	free(num);
	if (z < i)
		return (1);
	return (0);
}

void	sort_b_and_push_back(t_vars *vars)
{
	while (vars->b_stack.len != 0)
	{
		if (vars->b_stack.stack[0].index != find_max_index(vars->b_stack)
			&& !isnear(vars->b_stack, find_max_index(vars->b_stack)))
			rb(vars);
		else if (vars->b_stack.stack[0].index != find_max_index(vars->b_stack)
			&& isnear(vars->b_stack, find_max_index(vars->b_stack)))
			rrb(vars);
		else if (vars->b_stack.stack[0].index == find_max_index(vars->b_stack))
			pa(vars);
	}
}
