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

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-1 * n, fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		write(fd, (char []){(n % 10) + '0'}, 1);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	sort_array(t_vars *vars)
{
	int			j;
	int			i;
	int			temp;

	i = 0;
	while (i < vars->size - 1)
	{
		j = vars->size - 1;
		while (j > i)
		{
			if (vars->sorted_array[j - 1] > vars->sorted_array[j])
			{
				temp = vars->sorted_array[j - 1];
				vars->sorted_array[j - 1] = vars->sorted_array[j];
				vars->sorted_array[j] = temp;
			}
			j--;
		}
		i++;
	}
}
