/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:26:35 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/13 17:00:49 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_to(int fd, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!len)
		return (0);
	write(fd, str, len);
	return (len);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res);
}
