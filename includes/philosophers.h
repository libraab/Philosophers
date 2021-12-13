/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:52:51 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/13 14:26:07 by abouhlel         ###   ########.fr       */
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


#typedef struct s_data_t
{
	int	philo_nb;
	int eat_time;
	int think_time;
	int	sleep_time;
	int	death_time;
	int	eat_nb;
	int	forks_nb;
}				t_data;
//=============================================================================//
//*********************** F U N C T I O N S ***********************************//	
//=============================================================================//

#endif