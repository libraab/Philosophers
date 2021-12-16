/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/16 17:01:53 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_eat(t_philo *philo)
{
	long int tmp;
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->output);
	printf("At [%ld] philo %d is eating\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->output);
	philo->starving = get_time() - philo->start_time;
	tmp = philo->eat_time * 1000;
	while (tmp > 0)
	{
		usleep(10000);
		tmp -= 10000;
		if (!ft_check_death(philo))
		{
			philo->alive = 0;
			break;
		}
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (!philo->alive)
		return (0);
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	long int tmp;
	pthread_mutex_lock(&philo->output);
	printf("At [%ld] philo %d is sleeping\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->output);
	tmp = philo->sleep_time * 1000;
	while (tmp > 0)
	{
		usleep(10000);
		tmp -= 10000;
		if (!ft_check_death(philo))
		{
			philo->alive = 0;
			break;
		}
	}
	if (!philo->alive)
		return (0);
	return (1);
}

int	ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->output);
	printf("At [%ld] philo %d is thinking\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&philo->output);
	return (1);
}

void	*ft_action(void *ptr)
{
	t_philo *philo = ptr;
	while(philo->alive)
	{
		if (philo->id % 2 == 0)
			usleep(1000);
		if(!ft_eat(philo))
		{
			printf("At [%d] philo %d is dead while eating\n", philo->funeral, philo->id);
			break;
		}
		if (!ft_sleep(philo))
		{
			printf("At [%d] philo %d is dead while sleeping\n", philo->funeral, philo->id);
			break;
		}
		if (ft_think(philo) && !ft_check_death(philo))
		{
			printf("At [%d] philo %d is dead while thinking \n", philo->funeral, philo->id);
			break;
		}
	}
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