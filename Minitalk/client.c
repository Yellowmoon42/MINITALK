/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faacar <faacar@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:05:01 by faacar            #+#    #+#             */
/*   Updated: 2023/08/16 14:24:14 by faacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	static int	result;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
		result = ((*str++ - '0') + (result * 10));
	return (result);
}

void	send_data(char c, int pid)
{
	int	index;

	index = -1;
	while (++index < 8)
	{
		if (c << index & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	pid = ft_atoi(av[1]);
	if (ac == 3)
		while (*av[2])
			send_data(*av[2]++, pid);
	else
		ft_printf("CLIENT : FORMAT Error!\n");
	return (0);
}
