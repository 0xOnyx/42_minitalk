/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:49:38 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/14 15:20:22 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_buff {
	int	offset;
	char	value;
}	t_buff;


size_t	ft_strlen(char *str);
char	*ft_itoa(int n);
void	ft_putstr_to(int fd, char *str);
void	signal_user_handler(int sign);
void	exit_handler(int sign);


#endif
