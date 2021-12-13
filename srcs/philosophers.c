/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:00 by abouhlel          #+#    #+#             */
/*   Updated: 2021/12/13 15:07:20 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main (int ac, char **av)
{
	pthread_t t1;
	pthread_create (&1);
	(void)av;
	if (ac < 5 || ac > 6)
		return (0);
	if (ac == 5)
	{
		printf ("4 arg");
	}
	if (ac == 6)
	{
		printf ("5 arg");	
	}
	return (1);
}