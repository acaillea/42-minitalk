/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:59:07 by acaillea          #+#    #+#             */
/*   Updated: 2021/11/26 13:59:09 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_putstr_int(char *str)
{
	ft_putstr(str);
	return (-1);
}

int	ft_mini_atoi(char *str)
{
	int	neg;
	int	res;
	int	i;

	neg = 1;
	res = 0;
	i = 0;
	while (str && str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != 45)
			return (0);
		i++;
	}
	i = 0;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str && str[i])
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
}
