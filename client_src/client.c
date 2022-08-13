/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:09:54 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/13 17:39:18 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	t_message	msg;

	if (!parse_arg(argc, argv, &msg))
	{
		ft_putstr_to(2, "[ERROR]\tInvalid CLI argument\n");
		ft_putstr_to(2, "\tusage => ./client PID \"MESSAGE\"\n");
		return (1);
	}
	if (!send_message(msg))
	{
		ft_putstr_to(2, "[ERROR]\tthe message could not be send\n");
		return (1);
	}
	ft_putstr_to(1, "[INFO]\tthe message was send successfuly\n");
	return (0);
}
