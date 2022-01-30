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

void	big_sort(t_vars *vars)
{
	int	i;
	int	limit;

	i = 0;
	if (vars->size <= 100)
		limit = 15;
	else
		limit = 30;
	while (vars->a_stack.len != 0)
	{
		if (i > 1 && vars->a_stack.stack[0].index <= i)
		{
			pb(vars);
			rb(vars);
			i++;
		}
		else if (vars->a_stack.stack[0].index <= i + limit)
		{
			pb(vars);
			i++;
		}
		else if (vars->a_stack.stack[0].index >= i)
			ra(vars);
	}
	sort_b_and_push_back(vars);
}
