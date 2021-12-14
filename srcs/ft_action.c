/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 17:43:23 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_eat(int i)
{
	if (//forks unavailable)
		return (0);
	if (//forks available) //while (time to eat)
		printf("philo %d is eating\n", i + 1);
	return (1);
}

int	ft_sleep(int i)
{
	printf("philo %d is sleeping\n", i + 1);
	return (1);
}

int	ft_think(int i)
{
	printf("philo %d is thinking\n", i + 1);
	return (1);
}

void	*ft_action(void *ptr)
{
	int	*id;

	id = (int *)ptr;
	//pthread_mutex_unlock(&data->mutex[i]);
	//pthread_mutex_lock(&data->mutex[i]);
	ft_eat(*id);
	ft_sleep(*id);
	ft_think(*id);
	return (0);
}
