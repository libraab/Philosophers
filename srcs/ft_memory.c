/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:10:34 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 12:05:29 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init(t_data *data)
{
	data->t_tab = ft_calloc(sizeof(pthread_t), data->philo_nb);
	data->phil = ft_calloc(sizeof(t_philo), data->philo_nb);
	data->fork_nb = ft_calloc(sizeof(int), data->philo_nb);
}

void	ft_free(t_data *data)
{
	free (data->phil);
	free (data->t_tab);
	free (data->fork_nb);
}
