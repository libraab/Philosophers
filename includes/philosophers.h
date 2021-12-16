/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:52:51 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/16 16:36:43 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

# define MAX 2147483647

typedef struct s_philo
{
	int				eat_time;
	int				think_time;
	int				sleep_time;
	int				death_time;
	int				starving;
	int				*alive;
	int				funeral;
	long int		start_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t output;
	int				id;
}				t_philo;

typedef struct s_data
{
	pthread_mutex_t	*mutex;
	pthread_t		*t_tab;
	t_philo			*phil;
	int				philo_nb;
	int				eat_nb;
	int				timestamp;
}					t_data;

//=============================================================//
//*********************** F U N C T I O N S *******************//	
//=============================================================//

long long int		ft_atoi(char *str);
int					ft_isdigit(int c);
int					ft_check_limits(char **av, int ac);
int					ft_check_neg(char **av, int ac);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void	*b, int c, size_t len);
void				ft_stock_data(t_data *data, char **av);
void				ft_print(t_data data);
void				ft_init(t_data *data);
void				ft_free(t_data *data);
void				ft_create_thread(t_data *data);
void				*ft_action(void *ptr);
void				ft_create_mutex(t_data *data);
void				ft_destroy_mutex(t_data *data);
void				ft_threading(t_data *data);
long int    		get_time(void);
int					ft_sleep(t_philo *philo);
int					ft_think(t_philo *philo);
int					ft_eat(t_philo *philo);
int					ft_check_death(t_philo *philo);

#endif
