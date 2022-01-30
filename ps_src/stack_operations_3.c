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

void	rra(t_vars *vars)
{
	reverse_rotate(&vars->a_stack);
	write(vars->fd, "rra\n", 4);
}

void	rrb(t_vars *vars)
{
	reverse_rotate(&vars->b_stack);
	write(vars->fd, "rrb\n", 4);
}

void	rrr(t_vars *vars)
{
	reverse_rotate(&vars->a_stack);
	reverse_rotate(&vars->b_stack);
	write(vars->fd, "rrr\n", 4);
}
