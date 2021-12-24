/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:52:51 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/24 15:03:28 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/errno.h>
# include <signal.h>

# define MAX 2147483647

typedef struct s_data
{
	long int		eat_time;
	long int		sleep_time;
	long int		death_time;
	long int		start;
	int				starving;
	int				philo_nbr;
	int				lunch;
	int				id;
	int				alive;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	output;
	pthread_t		philo;
	sem_t			*forks;
	sem_t			*print;
	int				*pid;
}					t_data;

//*************************************************************//
//					* F U N C T I O N S *					   //	
//*************************************************************//

// MAIN
void			ft_init_values(t_data *data, int ac, char **av);
void			ft_init_mutex(t_data *data);
void			ft_create_thread(t_data *data);
void			ft_destroy_mutex(t_data *data);
long int		get_time(void);
// UTILS
void			*ft_memset(void	*b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
int				ft_isdigit(int c);
long long int	ft_atoi(char *str);
// ERROR
int				ft_check_limit(char **av, int ac);
int				ft_check_neg(char **av, int ac);
void			ft_usleep(long int start, long int eat_time);
// ROUTINE
void			*ft_routine(void *ptr);
void			ft_eat(t_data *philo);
void			ft_sleep(t_data *philo);
void			ft_think(t_data *philo);
void			*ft_funeral(void *ptr);

//*************************************************************//
//						* F R E E *							   //	
//*************************************************************//

void			ft_free(t_data *data);

//*************************************************************//
//						* B O N U S *							   //	
//*************************************************************//

void			ft_sharing_is_caring(t_data data);
void			ft_sleep_think(t_data *data);
void			ft_fork(t_data *data);

#endif
