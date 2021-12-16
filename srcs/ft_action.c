/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/16 11:40:24 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->output);
	printf("At [%ld] philo %d is eating\n", get_time() - philo->start_time, philo->id);
	usleep(philo->eat_time * 1000);
	pthread_mutex_unlock(&philo->output);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	phil[i]->starving = get_time();
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("At [%ld] philo %d is sleeping\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->output);
	usleep(philo->sleep_time * 1000);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("At [%ld] philo %d is thinking\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->output);
}

void	*ft_action(void *ptr)
{
	t_philo *philo = ptr;
	if (philo->id % 2 == 0)
		usleep(1000);
	while(1 && (gettime() - philo->starving <= philo->death_time))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	if (gettime() - philo->starving > philo->death_time)
		philo->philo_alive = 0;
	return (0);
}

long int    get_time(void)
{
    long int        time;
    struct timeval    current_time;

    time = 0;
    gettimeofday(&current_time, NULL);
    time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return (time);
}