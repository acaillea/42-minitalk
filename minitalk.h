/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:08:44 by acaillea          #+#    #+#             */
/*   Updated: 2021/11/25 19:47:16 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

# define ERR_CL "\033[31mError : Expected Format = ./client <PID> <Mess>\033[0m\n"
# define ERR_SER "\033[31mError : No Arguments Needed\033[0m\n"
# define ERR_SEND "\033[31mError : Signal Sending Issue...\033[0m\n"
# define ERR_RECEP "\033[31mError : Signal Reception Issue...\033[0m\n"
# define ERR_PID "\033[31mError : Invalid PID.\033[0m\n"

# define SLEEP_TIME 100
# define NBR_BITES 8

int		send_mess(pid_t pid, char *mess);
void	handle_mess(int signum);

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_putstr_int(char *str);
void	ft_putnbr(int n);
int		ft_mini_atoi(char *str);

#endif
