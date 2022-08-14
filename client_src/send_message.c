/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:04:32 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/14 15:27:48 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	send_char_to_server(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			if(kill(pid, SIGUSR1) < 0)
				return (0);
		}
		else
		{
			if(kill(pid, SIGUSR2) < 0)
				return (0);
		}
		c >>= 1;
		i++;
		usleep(TIME);
	}
	return (1);
}

int	send_message(t_message msg)
{
	char	*str;

	str = msg.str;
	while (*str)
	{
		if (!send_char_to_server(*str, msg.pid))
			return (0);
		str++;
	}
	return (1);
}
