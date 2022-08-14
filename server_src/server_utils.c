/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:49:46 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/14 15:21:18 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putchar_to(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr_to(int fd, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write(fd, str, len);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	signal_user_handler(int sign)
{
	static t_buff	current_buff;

	if (sign == SIGUSR1)
		current_buff.value |= 1 << current_buff.offset;
	current_buff.offset++;
	if (current_buff.offset == 8)
	{
		current_buff.offset = 0;
		ft_putchar_to(1, current_buff.value);
		current_buff.value = 0;
	}
}

void	exit_handler(int sign)
{
	if (sign == SIGTERM || sign == SIGKILL)
		exit(0);
}
