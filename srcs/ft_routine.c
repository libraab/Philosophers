/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/23 11:04:24 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_eat(t_data *phil)
{
	pthread_mutex_lock(&phil->right_fork);
	pthread_mutex_lock(&phil->output);
	printf("[%ld] id %d took right fork\n", get_time() - phil->start, phil->id);
	pthread_mutex_unlock(&phil->output);
	pthread_mutex_lock(phil->left_fork);
	pthread_mutex_lock(&phil->output);
	printf("[%ld] id %d took left fork\n", get_time() - phil->start, phil->id);
	pthread_mutex_unlock(&phil->output);
	phil->starving = get_time() - phil->start;
	pthread_mutex_lock(&phil->output);
	printf("[%ld] id %d is eating\n", get_time() - phil->start, phil->id);
	pthread_mutex_unlock(&phil->output);
	ft_usleep(phil->start, phil->eat_time);
	pthread_mutex_unlock(&phil->right_fork);
	pthread_mutex_unlock(phil->left_fork);
}

void	ft_sleep(t_data *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("[%ld] id %d is sleeping\n", get_time() - philo->start, philo->id);
	pthread_mutex_unlock(&philo->output);
	ft_usleep(philo->start, philo->sleep_time);
}

void	*ft_routine(void *ptr)
{
	t_data	*philo;

	philo = ptr;
	while (1 && philo->lunch > 0)
	{
		if (philo->id % 2 == 0)
			usleep (1000);
		ft_eat(philo);
		ft_sleep(philo);
		pthread_mutex_lock(&philo->output);
		printf("[%ld] id %d is thinking\n", get_time()
			- philo->start, philo->id);
		pthread_mutex_unlock(&philo->output);
		philo->lunch--;
	}
	return (0);
}

void	*ft_funeral(void *ptr)
{
	t_data		*philo;
	long int	janaza;
	int			i;

	philo = ptr;
	janaza = 0;
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
