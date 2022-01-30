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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_item
{
	int	num;
	int	index;
}				t_item;

typedef struct s_stack
{
	int		len;
	t_item	*stack;
}				t_stack;

typedef struct s_vars
{
	int			fd;
	int			size;
	t_stack		a_stack;
	t_stack		b_stack;
	int			*sorted_array;
}				t_vars;

void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
int		get_len(int n);
int		ft_atoi(const char *str);
int		ft_isnumeric(char *s);
int		ft_strcmp(char *s1, char *s2);

int		is_sequence_numeric(char **av, t_vars *vars);
int		is_sequence_int(char **av, t_vars *vars);
int		is_stack_unique(t_vars *vars);
int		is_stack_sorted(t_vars *vars);

void	fill_a_stack(char **av, t_vars *vars);
void	sort_array(t_vars *vars);
void	set_indexes(t_vars *vars);
int		find_min_index(t_stack stack);
int		find_max_index(t_stack stack);
int		isnear(t_stack stack, int median);
void	sort_b_and_push_back(t_vars *vars);

void	swap(t_stack *stack);
void	push(t_stack *dst, t_stack *src);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

void	sa(t_vars *vars);
void	sb(t_vars *vars);
void	ss(t_vars *vars);
void	pa(t_vars *vars);
void	pb(t_vars *vars);
void	ra(t_vars *vars);
void	rb(t_vars *vars);
void	rr(t_vars *vars);
void	rra(t_vars *vars);
void	rrb(t_vars *vars);
void	rrr(t_vars *vars);

void	sort_2(t_vars *vars);
void	sort_3(t_vars *vars);
void	sort_4_5(t_vars *vars);
void	big_sort(t_vars *vars);

#endif