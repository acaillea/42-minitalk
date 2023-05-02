/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:08:26 by acaillea          #+#    #+#             */
/*   Updated: 2021/11/25 19:27:10 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_mess(int signum)
{
	static int	c;
	static int	bit;
	static char	s;

	if (s != 1)
	{
		bit = NBR_BITES - 1;
		s = 1;
		c = 0;
	}
	if (bit >= 0)
	{
		if (signum == SIGUSR1)
			c |= (1 << bit);
		if (bit == 0)
		{
			ft_putchar(c);
			s = 0;
		}
		bit--;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
		return (ft_putstr_int(ERR_SER));
	pid = getpid();
	ft_putstr("Server's PID : ");
	ft_putnbr(pid);
	ft_putstr("\nMessages transmitted : \n");
	if (signal(SIGUSR1, handle_mess) == SIG_ERR)
		return (ft_putstr_int(ERR_RECEP));
	if (signal(SIGUSR2, handle_mess) == SIG_ERR)
		return (ft_putstr_int(ERR_RECEP));
	while (1)
		pause();
	return (0);
}
