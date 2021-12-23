/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:41:51 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/23 12:43:32 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_check_limit(char **av, int ac)
{
	if (ft_atoi(av[1]) > 200)
	{
		printf("Error: Too many philosophers\n");
		return (0);
	}
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
	{
		printf("Error: time exceeded limits\n");
		return (0);
	}
	if (ac == 6)
	{
		if (ft_atoi(av[5]) > MAX)
		{
			printf("Error: Too much eating\n");
			return (0);
		}
	}
	return (1);
}

int	ft_check_neg(char **av, int ac)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[4]) < 0)
	{
		printf("Error: invalid value\n");
		return (0);
	}
	if (ac == 6)
	{
		if (ft_atoi(av[5]) < 0)
		{
			printf("Error: invalid value\n");
			return (0);
		}
		if (ft_atoi(av[5]) == 0)
			return (0);
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*a;

	a = malloc(count * size);
	if (!a)
		return (0);
	ft_memset(a, 0, size * count);
	return (a);
}

long long int	ft_atoi(char *str)
{
	unsigned long int	result;
	int					sign;
	int					i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
