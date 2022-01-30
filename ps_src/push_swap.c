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

void	sort(t_vars *vars)
{
	sort_array(vars);
	set_indexes(vars);
	if (vars->size == 2)
		sort_2(vars);
	else if (vars->size == 3)
		sort_3(vars);
	else if (vars->size == 4 || vars->size == 5)
		sort_4_5(vars);
	else
		big_sort(vars);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->size = argc - 1;
	vars->fd = 1;
	if (is_sequence_numeric(argv, vars) && is_sequence_int(argv, vars))
	{
		vars->a_stack.stack = malloc(sizeof(t_item) * vars->size);
		vars->a_stack.len = vars->size;
		vars->b_stack.stack = malloc(sizeof(t_item) * vars->size);
		vars->b_stack.len = 0;
		vars->sorted_array = malloc(sizeof(int) * vars->size);
		fill_a_stack(argv, vars);
		if (!is_stack_unique(vars))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (!is_stack_sorted(vars))
			sort(vars);
	}
	else
		write(2, "Error\n", 6);
	exit(0);
}
