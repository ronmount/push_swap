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

void	sort_2(t_vars *vars)
{
	if (vars->a_stack.stack[0].index > vars->a_stack.stack[1].index)
		sa(vars);
}

void	sort_3(t_vars *vars)
{
	t_stack	stack;

	stack = vars->a_stack;
	if (stack.stack[0].index == find_max_index(stack))
		ra(vars);
	if (stack.stack[0].index == find_min_index(stack)
		&& stack.stack[1].index == find_max_index(stack))
	{
		rra(vars);
		sa(vars);
	}
	if (stack.stack[0].index != find_min_index(stack)
		&& stack.stack[0].index > stack.stack[1].index)
		sa(vars);
	if (stack.stack[0].index != find_min_index(stack)
		&& stack.stack[0].index < stack.stack[1].index)
		rra(vars);
}

void	sort_4_5(t_vars *vars)
{
	int		i;

	i = 0;
	while (i < vars->size - 2)
	{
		if (vars->a_stack.stack[0].index > find_min_index(vars->a_stack)
			&& !isnear(vars->a_stack, find_min_index(vars->a_stack)))
			ra(vars);
		else if (vars->a_stack.stack[0].index > find_min_index(vars->a_stack)
			&& isnear(vars->a_stack, find_min_index(vars->a_stack)))
			rra(vars);
		else
		{
			pb(vars);
			i++;
		}
	}
	if (vars->a_stack.stack[0].index != find_min_index(vars->a_stack))
		sa(vars);
	while (vars->b_stack.len)
		pa(vars);
}
