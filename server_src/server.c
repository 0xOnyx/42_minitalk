/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:11:48 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/14 15:24:50 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	display_pid(void)
{
	pid_t	pid;
	char	*value;

	pid = getpid();
	ft_putstr_to(1, "[INFO]\tpid => ");
	value = ft_itoa(pid);
	if (!value)
	{
		ft_putstr_to(2, "\n[ERROR]\tft_itoa() error\n");
		exit(1);
	}
	ft_putstr_to(1, value);
	free(value);
	ft_putstr_to(1, "\n");
}

void	ft_init_signal(void)
{
	signal(SIGUSR1, &signal_user_handler);
	signal(SIGUSR2, &signal_user_handler);
	signal(SIGTERM, &exit_handler);
	signal(SIGKILL, &exit_handler);
}

int	main(void)
{
	display_pid();
	ft_init_signal();
	while (1)
		pause();
	return (0);
}
