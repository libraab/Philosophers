/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:10:55 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 17:49:55 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_create_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i + 1 < data->philo_nb)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		data->mutex[i] = &data->philo[i]->right_fork;
		data->mutex[i + 1] = &data->philo[i]->left_fork;
		i++;
	}
	pthread_mutex_init(&data->mutex[i], NULL);
	data->mutex[i] = &data->philo[i]->right_fork;
	data->mutex[0] = &data->philo[i]->left_fork;
	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_unlock(&data->mutex[i]);
		i++;
	}
}

void	ft_destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
}
