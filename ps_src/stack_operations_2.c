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

void	ra(t_vars *vars)
{
	rotate(&vars->a_stack);
	write(vars->fd, "ra\n", 3);
}

void	rb(t_vars *vars)
{
	rotate(&vars->b_stack);
	write(vars->fd, "rb\n", 3);
}

void	rr(t_vars *vars)
{
	rotate(&vars->a_stack);
	rotate(&vars->b_stack);
	write(vars->fd, "rr\n", 3);
}
