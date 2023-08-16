/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faacar <faacar@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:05:25 by faacar            #+#    #+#             */
/*   Updated: 2023/08/16 14:19:26 by faacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig)
{
	static int	index;
	static char	chr;

	if (sig == SIGUSR1)
		chr = (chr << 1) | 1;
	else
		chr = (chr << 1);
	index++;
	if (index == 8)
	{
		ft_printf("%c", chr);
		index = 0;
		chr = 0;
	}
}

int	main(void)
{
	ft_printf("SERVER : Server started\nPID -> %d\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
}
