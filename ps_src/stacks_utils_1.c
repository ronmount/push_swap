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

int	find_index(int *array, int num)
{
	int	i;

	i = 0;
	while (array[i] != num)
		i++;
	return (i);
}

void	set_indexes(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->size)
		vars->a_stack.stack[i].index = find_index(
				vars->sorted_array,
				vars->a_stack.stack[i].num);
}

int	find_min_index(t_stack stack)
{
	int	i;
	int	index;

	i = 0;
	index = stack.stack[i].index;
	while (++i < stack.len)
		if (stack.stack[i].index < index)
			index = stack.stack[i].index;
	return (index);
}

int	find_max_index(t_stack stack)
{
	int	i;
	int	index;

	i = 0;
	index = stack.stack[i].index;
	while (++i < stack.len)
		if (stack.stack[i].index > index)
			index = stack.stack[i].index;
	return (index);
}

void	fill_a_stack(char **av, t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->size)
	{
		vars->a_stack.stack[i].num = ft_atoi(av[i + 1]);
		vars->sorted_array[i] = vars->a_stack.stack[i].num;
	}
}
