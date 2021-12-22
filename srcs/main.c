/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/22 12:23:23 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_values(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		data->eat_time = ft_atoi(av[3]);
		data->sleep_time = ft_atoi(av[4]);
		data->death_time = ft_atoi(av[2]);
		data->philo_nbr = ft_atoi(av[1]);
		data->start = 0;
		if (ac == 6)
			data->lunch = ft_atoi(av[5]);
		else
			data->lunch = MAX;
		data->id = i + 1;
		i++;
	}
}

long int	get_time(void)
{
	long int		time;
	struct timeval	current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_create_thread(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = data->philo_nbr;
	while (i < count)
	{
		data->start = get_time();
		pthread_create(&data, NULL, &ft_routine, &data->philo);
		usleep(10);
		i++;
	}
}

void	ft_init_mutex(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = data->philo_nbr;
	while (i + 1 < count)
	{
		pthread_mutex_init(&data->right_fork, NULL);
		pthread_mutex_init(&data->left_fork, NULL);
		pthread_mutex_init(&data->output, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), ft_atoi(av[1]) + 1);
	if (ac < 5 || ac > 6)
		return (0);
	if (!ft_check_neg(av, ac) || !ft_check_limit(av, ac))
		return (0);
	ft_init_values(&data, ac, av);
	ft_init_mutex(&data);
	ft_create_thread(&data);
	ft_free(&data);
	return (1);
}
