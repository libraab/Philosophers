/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharing_is_caring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:27:54 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/23 18:05:36 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_sharing_is_caring(t_data data)
{
	while (data.lunch > 0)
	{
		if (data.id % 2 == 0)
			usleep(1000);
		sem_wait(data.forks);
		sem_wait(data.forks);
		
		sem_wait(data.print);
		printf("[%ld] id %d took 2 forks\n", get_time() - data.start, data.id);
		sem_post(data.print);
		
		sem_wait(data.print);
		data.starving = get_time() - data.start;
		printf("[%ld] id %d is eating\n", get_time() - data.start, data.id);
		sem_post(data.print);
		
		ft_usleep(data.start, data.eat_time);
		
		sem_post(data.forks);
		sem_post(data.forks);
		
		sem_wait(data.print);
		printf("[%ld] id %d is sleeping\n", get_time() - data.start, data.id);
		sem_post(data.print);
		
		ft_usleep(data.start, data.sleep_time);
		
		sem_wait(data.print);
		printf("[%ld] id %d is thinking\n", get_time() - data.start, data.id);
		sem_post(data.print);
		data.lunch--;
	}
	exit(0);
}

void	*ft_funeral(void *ptr)
{
	t_data		*philo;
	int			i;

	philo = ptr;
	i = 0;
	while (1 && philo->lunch > 0)
	{
		if (get_time() - philo->start >= philo->starving + philo->death_time)
		{
			philo->alive = 0;
			printf("[%ld] id %d died\n", get_time() - philo->start, philo->id);
			return (0);
		}
	}
	return (0);
}
