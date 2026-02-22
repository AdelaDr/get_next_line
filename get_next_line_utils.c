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
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	if (!str)
    return (NULL);
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


// strjoin //
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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

// remove line //
static int	find_newline(char *stash)
{
	int	i;

	if (!stash)
		return (-1);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		return (i);
	return (-1);
}

static char	*create_newstash(char *stash, int start)
{
	char	*newstash;
	int		len;
	int		j;

	len = 0;
	while (stash[start + len])
		len++;
	newstash = malloc(len + 1);
	if (!newstash)
		return (NULL);
	j = 0;
	while (j < len)
	{
		newstash[j] = stash[start + j];
		j++;
	}
	newstash[j] = '\0';
	return (newstash);
}

char	*ft_remove_line(char *stash)
{
	char	*newstash;
	int		i;

	if (!stash)
		return (NULL);
	i = find_newline(stash);
	if (i == -1)
	{
		free(stash);
		return (NULL);
	}
	i++;
	newstash = create_newstash(stash, i);
	free(stash);
	return (newstash);
}