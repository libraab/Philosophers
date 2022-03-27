/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:25:36 by abouhlel          #+#    #+#             */
/*   Updated: 2022/03/27 15:50:07 by abouhlel         ###   ########.fr       */
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
		data[i].starving_mode = 0;
		data[i].birth = 0;
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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
			if (data[i].id % 2 == 0)
				usleep(1000);
			ft_sharing_is_caring(data[i]);
		}
		else
			data->pid[i] = x;
		i++;
	}
	wait(0);
	i = 0;
	while (i < data->philo_nbr)
		kill(data->pid[i++], SIGINT);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 5 || ac > 6)
		return (0);
	data = ft_calloc(sizeof(t_data), ft_atoi(av[1]));
	data->pid = ft_calloc(sizeof(int), ft_atoi(av[1]));
	if (!ft_check_neg(av, ac) || !ft_check_limit(av, ac))
		return (0);
	sem_unlink("forks");
	data->forks = sem_open("forks", O_CREAT, 0644, ft_atoi(av[1]));
	sem_unlink("print");
	data->print = sem_open("print", O_CREAT, 0644, 1);
	ft_init_values(data, ac, av);
	ft_fork(data);
	sem_close(data->forks);
	sem_close(data->print);
	free (data);
	free (data->pid);
	return (1);
}
