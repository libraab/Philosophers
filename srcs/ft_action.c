/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:25:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 18:31:10 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	printf("philo %d is eating\n", philo->id);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	printf("philo %d is sleeping\n", philo->id);
	return (1);
}

int	ft_think(t_philo *philo)
{
	printf("philo %d is thinking\n", philo->id);
	return (1);
}

void	*ft_action(void *ptr)
{
	t_philo *philo = (t_philo *)ptr;
	ft_eat(philo);
	ft_sleep(philo);
	ft_think(philo);
	return (0);
}
