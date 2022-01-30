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
#include "get_next_line.h"

int	check_command(t_vars *vars, char *line)
{
	if (!(ft_strcmp(line, "sa\n")))
		sa(vars);
	else if (!(ft_strcmp(line, "sb\n")))
		sb(vars);
	else if (!(ft_strcmp(line, "ss\n")))
		ss(vars);
	else if (!(ft_strcmp(line, "pa\n")))
		pa(vars);
	else if (!(ft_strcmp(line, "pb\n")))
		pb(vars);
	else if (!(ft_strcmp(line, "ra\n")))
		ra(vars);
	else if (!(ft_strcmp(line, "rb\n")))
		rb(vars);
	else if (!(ft_strcmp(line, "rr\n")))
		rr(vars);
	else if (!(ft_strcmp(line, "rra\n")))
		rra(vars);
	else if (!(ft_strcmp(line, "rrb\n")))
		rrb(vars);
	else if (!(ft_strcmp(line, "rrr\n")))
		rrr(vars);
	else
		return (0);
	return (1);
}

void	run_reader(t_vars *vars)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!check_command(vars, line))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		free(line);
	}
	if (is_stack_sorted(vars) && vars->b_stack.len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->size = argc - 1;
	vars->fd = -1;
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
		run_reader(vars);
	}
	else
		write(2, "Error\n", 6);
	exit(0);
}
