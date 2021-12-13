/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/13 20:16:02 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_stock_data(t_philo *phil, char **av, int ac)
{
	int i;

	i = 0;
	while(i < ac)
	{
		phil[i].death_time = ft_atoi(av[2]);
		phil[i].eat_time = ft_atoi(av[3]);
		phil[i].sleep_time = ft_atoi(av[4]);
		phil[i].think_time = 0;
		i++;
	}
}

int main (int ac, char **av)
{
	t_data data;
	
	// pthread_t t1;
	// pthread_create (&1);
	(void)av;
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
		ft_stock_data(data.phil, av, ac);
		ft_print(data);
		free (data.phil);
	}
	return (1);
}
