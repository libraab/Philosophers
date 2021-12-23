/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:25:36 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/23 18:08:23 by abouhlel         ###   ########.fr       */
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
		data[i].start = 0;
		data[i].alive = 1;
		data[i].id = i + 1;
		data[i].forks = data->forks;
		data[i].print = data->print;
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

void	ft_usleep(long int start, long int eat_time)
{
	int	tmp;

	tmp = get_time() - start;
	while (get_time() - start < tmp + eat_time)
		usleep(10);
}

void	ft_fork(t_data *data)
{
	int	i;
	int	x;

	i = 0;
	while (i < data->philo_nbr)
	{
		x = fork();
		if (x == 0)
		{
			data[i].start = get_time();
			ft_sharing_is_caring(data[i]);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	//pthread_t	azraeel;

	if (ac < 5 || ac > 6)
		return (0);
	data = ft_calloc(sizeof(t_data), ft_atoi(av[1]));
	if (!ft_check_neg(av, ac) || !ft_check_limit(av, ac))
		return (0);
	sem_unlink("forks");
	data->forks = sem_open("forks", O_CREAT, 0644, ft_atoi(av[1]));
	if (data->forks == SEM_FAILED)
		printf("%s\n" ,strerror(errno));
	sem_unlink("print");
	data->print = sem_open("print", O_CREAT, 0644, 1);
	ft_init_values(data, ac, av);
	ft_fork(data);
	wait(0);
	//pthread_create(&azraeel, NULL, &ft_funeral, data);
	//pthread_join(azraeel, NULL);
	sem_close(data->forks);
	sem_close(data->print);
	printf("le pere mort\n");
	free (data);
	return (1);
}
