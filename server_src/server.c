/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:11:48 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/13 18:27:04 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	display_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_to("[INFO]\tpid => ");
	ft_putstr_to(ft_itoa(pid));
	ft_putstr("\n");
}

void	ft_init_signal(void)
{
	signal(
}

int	main(void)
{
	display_pid();
	ft_init_signal();
	while (1)
		pause();
	return (0);
}
