/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/22 12:10:00 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_eat(t_data *phil)
{
	long int	tmp;

	tmp = phil->eat_time * 1000;
	pthread_mutex_lock(phil->right_fork);
	printf("[%ld] nbr %d took right fork\n", get_time() - phil->start, phil->id);
	pthread_mutex_lock(phil->left_fork);
	printf("[%ld] nbr %d took left fork\n", get_time() - phil->start, phil->id);
	pthread_mutex_lock(&phil->output);
	printf("[%ld] nbr %d is eating\n", get_time() - phil->start, phil->id);
	pthread_mutex_unlock(&phil->output);
	usleep(tmp);
	pthread_mutex_unlock(phil->left_fork);
	pthread_mutex_unlock(phil->right_fork);
	return (1);
}

int	ft_sleep(t_data *philo)
{
	long int	tmp;

	tmp = philo->sleep_time * 1000;
	pthread_mutex_lock(&philo->output);
	printf("[%ld] philo %d is sleeping\n", get_time() - philo->start, philo->id);
	pthread_mutex_unlock(&philo->output);
	usleep(tmp);
	return (1);
}

int	ft_think(t_data *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("[%ld] philo %d is thinking\n", get_time() - philo->start, philo->id);
	pthread_mutex_unlock(&philo->output);
	return (1);
}

void	*ft_routine(void *ptr)
{
	t_data	*philo;

	philo = ptr;
	while (1)
	{
		if (philo->id % 2 == 0)
			usleep (10);
		if (!ft_eat(philo) || !ft_sleep(philo) || !ft_think(philo))
		{
			printf("[%d] philo %d died\n", get_time() - philo->start, philo->id);
			break ;
		}
	}
	return (0);
}
