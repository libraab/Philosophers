/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:10:55 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 18:30:20 by abouhlel         ###   ########.fr       */
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
		data->phil[i].right_fork = &data->mutex[i];
		data->phil[i].left_fork = &data->mutex[i + 1];
		i++;
	}
	pthread_mutex_init(&data->mutex[i], NULL);
	data->phil[i].right_fork = &data->mutex[i];
	data->phil[i].left_fork = &data->mutex[0];
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
