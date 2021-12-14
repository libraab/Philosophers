/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 11:25:03 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_check_limits(char **av)
{
	if (ft_atoi(av[1]) > 200)
	{
		printf("Error: Too many philosophers\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
	{
		printf("Error: time exceeded limits\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(av[5]) > MAX)
	{
		printf("Error: Too much eating\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	ft_check_neg(char **av)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[5]) < 0)
	{
		printf("Error: invalid value\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(av[5]) == 0)
		return (0);
	return (1);
}
