/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:52:51 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/13 20:13:44 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>

# define MAX 2147483647

typedef struct s_philo
{
	int eat_time;
	int think_time;
	int	sleep_time;
	int	death_time;
}				t_philo;

typedef struct s_data
{
	t_philo	*phil;
	int		philo_nb;
	int		fork_nb;
	int		eat_nb;
}				t_data;

//=============================================================================//
//*********************** F U N C T I O N S ***********************************//	
//=============================================================================//

long long int		ft_atoi(char *str);
int					ft_isdigit(int c);
int					ft_check_limits(char **av);
int					ft_check_neg(char **av);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void	*b, int c, size_t len);
void				ft_stok_data(t_philo *phil, char **av, int ac);
void				ft_print(t_data data);

#endif