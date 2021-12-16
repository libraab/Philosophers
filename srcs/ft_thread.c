/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:11:21 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/16 15:51:29 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->phil[i].start_time = get_time();
		pthread_create(&data->t_tab[i], NULL, &ft_action, &data->phil[i]);
		usleep(10);
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(data->t_tab[i], NULL);
		i++;
	}
}