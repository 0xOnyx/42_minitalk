/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:42:00 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/13 17:39:45 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	parse_arg(int argc, char **argv, t_message *msg)
{
	if (argc != 3 || !argv || !ft_isdigit(argv[1]))
		return (0);
	msg->pid = ft_atoi(argv[1]);
	msg->str = argv[2];
	return (1);
}
