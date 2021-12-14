/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:11:44 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 12:09:31 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_print(t_data data)
{
	int	i;

	i = 0;
	printf("\n{printing data}\n");
	printf("\nphilo number is -->[%d]\n", data.philo_nb);
	while (i < data.philo_nb)
	{
		printf("\n----------------------\n");
		printf("     [PHILO %d]\n", i + 1);
		printf("think time is   -->[%d]\n", data.phil[i].think_time);
		printf("eat time is     -->[%d]\n", data.phil[i].eat_time);
		printf("sleep time is   -->[%d]\n", data.phil[i].sleep_time);
		printf("death time is   -->[%d]\n", data.phil[i].death_time);
		printf("----------------------\n");
		i++;
	}
	printf("\neach of them eats -->[%d] time\n", data.eat_nb);
}
