/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:49:32 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/14 15:24:15 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static size_t	max_len(int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_fill_tab(int nb, char *tab, size_t len)
{
	size_t	i;

	i = len;
	if (nb < 0)
	{
		tab[0] = '-';
		nb *= -1;
		tab++;
		i--;
	}
	while (i-- > 0)
	{
		tab[i] = '0' + (nb % 10);
		nb /= 10;
	}
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strdup(char *s)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, len + 1);
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	if (n >= 2147483647)
		return (ft_strdup("2147483647"));
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	len = max_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_fill_tab(n, res, len);
	res[len] = '\0';
	return (res);
}
