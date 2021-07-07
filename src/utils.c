/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:01:35 by charles           #+#    #+#             */
/*   Updated: 2021/06/22 21:01:38 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	abs_value(int a)
{
	if (a < 0)
		return (-a);
	else
    	return (a);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*n;
	size_t	i;

	i = 0;
	if (!(n = malloc(size * count)))
		return (NULL);
	while (i < (size * count))
	{
		((char*)n)[i] = 0;
		i++;
	}
	return (n);
}

int		ft_atoi(const char *str)
{
	int					i;
	int					signe;
	long long int		digit;

	i = 0;
	digit = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		signe = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		digit = digit * 10 + (str[i] - '0');
		i++;
	}
	return (digit * signe);
}

size_t	ft_strlen( char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	malloc_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
}