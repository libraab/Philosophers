/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/16 16:52:05 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_stock_data(t_data *data, char **av)
{
	int	i;
	int alive;

	i = 0;
	alive = 1;
	while (i < data->philo_nb)
	{
		data->phil[i].death_time = ft_atoi(av[2]);
		data->phil[i].eat_time = ft_atoi(av[3]);
		data->phil[i].sleep_time = ft_atoi(av[4]);
		data->phil[i].think_time = 0;
		data->phil[i].id = i + 1;
		data->phil[i].alive = &alive;
		i++;
	}
}

int ft_check_death(t_philo *philo)
{
	if (get_time() - philo->start_time >= philo->starving + philo->death_time)
	{
		philo->funeral = get_time() - philo->start_time;
		return (0);
	}
	return (1);
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
		ft_check_limits(av, ac);
		if (ft_check_neg(av, ac) == 0)
			return (0);
		ft_init(&data);
		ft_stock_data(&data, av);
		ft_create_mutex(&data);
		ft_create_thread(&data);
		ft_destroy_mutex(&data);
		ft_free(&data);
	}
	return (1);
}
