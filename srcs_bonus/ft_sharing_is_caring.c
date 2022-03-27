/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharing_is_caring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:27:54 by abouhlel          #+#    #+#             */
/*   Updated: 2022/03/27 18:00:15 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_sleep_think(t_data *data)
{
	sem_wait(data->print);
	printf("[%ld] id %d is sleeping\n", get_time() - data->birth, data->id);
	sem_post(data->print);
	ft_usleep(data->birth, data->sleep_time);
	sem_wait(data->print);
	printf("[%ld] id %d is thinking\n", get_time() - data->birth, data->id);
	sem_post(data->print);
}

void	ft_sharing_is_caring(t_data data)
{
	pthread_t	azraeel;

	data.birth = get_time();
	pthread_create(&azraeel, NULL, &ft_funeral, &data);
	while (data.lunch > 0)
	{
		sem_wait(data.forks);
		sem_wait(data.forks);
		sem_wait(data.print);
		printf("[%ld] id %d took 2 forks\n", get_time() - data.birth, data.id);
		sem_post(data.print);
		sem_wait(data.print);
		data.starving = get_time() - data.birth;
		printf("[%ld] id %d is eating\n", get_time() - data.birth, data.id);
		sem_post(data.print);
		ft_usleep(data.birth, data.eat_time);
		sem_post(data.forks);
		sem_post(data.forks);
		ft_sleep_think(&data);
		data.lunch--;
	}
	pthread_join(azraeel, NULL);
	exit(0);
}

void	*ft_funeral(void *ptr)
{
	t_data		*philo;

	philo = ptr;
	while (philo->lunch > 0)
	{
		if (get_time() - philo->birth >= philo->starving + philo->death_time)
		{
			printf("[%ld] philo %d ->💀\n", get_time() - philo->birth, philo->id);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

long int	get_time(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int birth, long int eat_time)
{
	int	tmp;

	tmp = get_time() - birth;
	while (get_time() - birth < tmp + eat_time)
		usleep(10);
}
