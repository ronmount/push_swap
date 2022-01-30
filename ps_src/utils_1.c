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

int	ft_isnumeric(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)(res * sign));
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		--len;
		result[len] = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
