/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 18:23:44 by abouhlel         ###   ########.fr       */
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
		data->phil[i].id = i + 1;
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
		ft_threading(&data);
		//ft_print(data);
		ft_destroy_mutex(&data);
		ft_free(&data);
	}
	return (1);
}
