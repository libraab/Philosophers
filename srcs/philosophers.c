/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 17:05:00 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_stock_data(t_data *data, char **av)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->phil[i].death_time = ft_atoi(av[2]);
		data->phil[i].eat_time = ft_atoi(av[3]);
		data->phil[i].sleep_time = ft_atoi(av[4]);
		data->phil[i].think_time = 0;
		i++;
	}
}

void	ft_create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&data->t_tab[i], NULL, &ft_action, &i);
		usleep(10);
		i++;
	}
}

void	ft_create_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_init(&data->m_tab[i], NULL);
		i++;
	}
}

void	ft_destroy_mutex(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_destroy(&data->m_tab[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	
	if (ac < 5 || ac > 6)
		return (0);
	if (ac >= 5)
	{
		data.philo_nb = ft_atoi(av[1]);
		if (ac == 6)
			data.eat_nb = ft_atoi(av[5]);
		else
			data.eat_nb = 1;
		ft_check_limits(av);
		if (ft_check_neg(av) == 0)
			return (0);
		ft_init(&data);
		ft_stock_data(&data, av);
		ft_create_mutex(&data);
		ft_create_thread(&data);

		i = 0;
		while (i < data->philo_nb)
		{
			pthread_join(data->t_tab[i], NULL);
			i++;
		}
		
		//ft_print(data);
		ft_destroy_mutex(&data);
		ft_free(&data);
	}
	return (1);
}
