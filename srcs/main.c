/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/22 17:37:10 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_values(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		data[i].eat_time = ft_atoi(av[3]);
		data[i].sleep_time = ft_atoi(av[4]);
		data[i].death_time = ft_atoi(av[2]);
		data[i].philo_nbr = ft_atoi(av[1]);
		data[i].starving = 0;
		data[i].start = 55;
		data[i].alive = 1;
		data[i].id = i + 1;
		if (ac == 6)
			data[i].lunch = ft_atoi(av[5]);
		else
			data[i].lunch = MAX;
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
	int			i;
	int			count;
	pthread_t	azraeel;

	i = 0;
	count = data->philo_nbr;
	while (i < count)
	{
		data[i].start = get_time();
		pthread_create(&data[i].philo, NULL, &ft_routine, &data[i]);
		i++;
	}
	pthread_create(&azraeel, NULL, &ft_funeral, data);
	pthread_join(azraeel, NULL);
}

void	ft_init_mutex(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = data->philo_nbr;
	while (i < count)
	{
		data[i].left_fork = NULL;
		pthread_mutex_init(&data[i].output, NULL);
		pthread_mutex_init(&data[i].right_fork, NULL);
		if (i == count - 1)
			data[i].left_fork = &data[0].right_fork;
		else
			data[i].left_fork = &data[i + 1].right_fork;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 5 || ac > 6)
		return (0);
	data = ft_calloc(sizeof(t_data), ft_atoi(av[1]));
	if (!ft_check_neg(av, ac) || !ft_check_limit(av, ac))
		return (0);
	ft_init_values(data, ac, av);
	ft_init_mutex(data);
	ft_create_thread(data);
	ft_free(data);
	return (1);
}
