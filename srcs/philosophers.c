/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/14 10:14:23 by abouhlel         ###   ########.fr       */
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

void	*ft_action()
{
	printf("philo is thinking\n");
	uslee(1);
	printf("philo is eating\n");
	uslee(1);
	printf("philo is sleeping\n");
	uslee(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, &ft_action, NULL);
	pthread_create(&t2, NULL, &ft_action, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
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
		{
			printf("Nothing is done\n");
			return (0);
		}
		data.phil = ft_calloc(sizeof(t_philo), data.philo_nb);
		ft_stock_data(&data, av);
		ft_print(data);
		free (data.phil);
	}
	return (1);
}
