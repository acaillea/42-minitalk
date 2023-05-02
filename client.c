/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:06:19 by acaillea          #+#    #+#             */
/*   Updated: 2021/11/25 19:49:26 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_mess(pid_t pid, char *mess)
{
	int	i;
	int	bit;

	i = 0;
	while (mess && mess[i])
	{
		bit = NBR_BITES - 1;
		while (bit >= 0)
		{
			if (mess[i] & (1 << bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					return (-1);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					return (-1);
			usleep(SLEEP_TIME);
			bit--;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		return (ft_putstr_int(ERR_CL));
	pid = ft_mini_atoi(av[1]);
	if (pid > 0 && pid < 4194304)
	{
		if (send_mess(pid, av[2]))
			return (ft_putstr_int(ERR_SEND));
	}
	else
		return (ft_putstr_int(ERR_PID));
	send_mess(pid, "\n");
	return (0);
}
