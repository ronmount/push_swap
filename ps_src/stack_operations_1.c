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

void	sa(t_vars *vars)
{
	swap(&vars->a_stack);
	write(vars->fd, "sa\n", 3);
}

void	sb(t_vars *vars)
{
	swap(&vars->b_stack);
	write(vars->fd, "sb\n", 3);
}

void	ss(t_vars *vars)
{
	swap(&vars->a_stack);
	swap(&vars->b_stack);
	write(vars->fd, "ss\n", 3);
}

void	pa(t_vars *vars)
{
	push(&vars->a_stack, &vars->b_stack);
	write(vars->fd, "pa\n", 3);
}

void	pb(t_vars *vars)
{
	push(&vars->b_stack, &vars->a_stack);
	write(vars->fd, "pb\n", 3);
}
