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

void	swap(t_stack *stack)
{
	t_item	temp;

	if (stack->len > 1)
	{
		temp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = temp;
	}
}

void	push(t_stack *dst, t_stack *src)
{
	int	i;

	if (src->len > 0)
	{
		i = dst->len + 1;
		while (--i > 0)
			dst->stack[i] = dst->stack[i - 1];
		dst->stack[0] = src->stack[0];
		i = -1;
		while (++i < src->len - 1)
			src->stack[i] = src->stack[i + 1];
		dst->len += 1;
		src->len -= 1;
	}
}

void	rotate(t_stack *stack)
{
	int		i;
	t_item	temp;

	i = -1;
	if (stack->len > 1)
	{
		temp = stack->stack[0];
		while (++i < stack->len - 1)
			stack->stack[i] = stack->stack[i + 1];
		stack->stack[i] = temp;
	}
}

void	reverse_rotate(t_stack *stack)
{
	int		i;
	t_item	temp;

	i = stack->len;
	if (stack->len > 1)
	{
		temp = stack->stack[stack->len - 1];
		while (--i > 0)
			stack->stack[i] = stack->stack[i - 1];
		stack->stack[0] = temp;
	}
}
