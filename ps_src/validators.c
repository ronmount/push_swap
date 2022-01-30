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

int	is_sequence_numeric(char **av, t_vars *vars)
{
	int	i;

	i = 0;
	while (++i < vars->size + 1)
		if (!ft_isnumeric(av[i]))
			return (0);
	return (1);
}

int	is_sequence_int(char **av, t_vars *vars)
{
	int		i;
	char	*s;

	i = 0;
	while (++i < vars->size + 1)
	{
		s = ft_itoa(ft_atoi(av[i]));
		if (ft_strcmp(s, av[i]) != 0)
		{
			free(s);
			return (0);
		}
		free(s);
	}
	return (1);
}

int	is_stack_unique(t_vars *vars)
{
	int	i;
	int	n;

	i = -1;
	n = vars->size;
	while (++i < n * n)
		if (vars->a_stack.stack[i / n].num == vars->a_stack.stack[i % n].num
			&& i / n != i % n)
			return (0);
	return (1);
}

int	is_stack_sorted(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->size - 1)
		if (vars->a_stack.stack[i].num > vars->a_stack.stack[i + 1].num)
			return (0);
	return (1);
}
