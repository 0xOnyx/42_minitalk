/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:16:59 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/13 17:37:32 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <unistd.h>

typedef struct s_message
{
	char	*str;
	int		pid;
}	t_message;

int	parse_arg(int argc, char **argv, t_message *msg);
int	send_message(t_message msg);
int	send_char_to_server(char c, int pid);

int	ft_putstr_to(int fd, char *str);
int	ft_strlen(char *str);
int	ft_isdigit(char *str);
int	ft_atoi(char *str);

#endif
