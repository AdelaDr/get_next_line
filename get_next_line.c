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

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *stash;
	char buffer[BUFFER_SIZE + 1];
	char *newline;
	int bytes;
	int i;
	char *res;
	int j;

	newline = NULL;

	while (newline == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		newline = ft_strchr(stash, '\n');
	}
	i = 0;
	if (bytes >= 0)
	{
		j = ft_strlen(stash);
		res = malloc(j + 2);
	    while (stash[i] != '\n' && stash[i] != '\0')
		{
			res[i] = stash[i];
			i++;
		}
		if(stash[i] == '\n')
		{
			res[i] = '\n';
			i++;
		}
		res[i] = '\0';
		stash = ft_remove_line(stash);
		return (res);
	}
}


