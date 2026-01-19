/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrahoto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:12:34 by adrahoto          #+#    #+#             */
/*   Updated: 2026/01/08 22:12:34 by adrahoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}


// strjoin
static void write_res(char *stash, char *buffer, char *res)
{	int i;
	int j;
	
	i = 0;
	j = 0;
	if (stash != NULL)
	{
		while (stash[i])
			{
				res[j] = stash[i];
				i++;
				j++;
			}
	}
	i = 0;
	while (buffer[i])
	{
		res[j] = buffer[i];
		i++;
		j++;
	}
	res[j] = '\0';
}

char	*ft_strjoin(char *stash, char *buffer)
{
	int i;
	int j;
	char *res;

	i = 0;
	j = 0;
	if (stash != NULL)
	{
		while (stash[i])
			i++;
	}
	while (buffer[j])
		j++;
	res = malloc(i+j+1);
	if (!res)
		return (NULL);
	write_res(stash, buffer, res);
	free(stash);
	return (res);
}