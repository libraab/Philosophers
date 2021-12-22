/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/22 18:06:07 by abouhlel         ###   ########.fr       */
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

void	ft_usleep(long int start, long int eat_time)
{
	int	tmp;

	tmp = get_time() - start;
	while (get_time() - start < tmp + eat_time)
		usleep(10);
}
