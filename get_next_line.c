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
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char stash;
    char buffer[BUFFER_SIZE + 1];
    char *newline;
    int bytes;

    while (newline == NULL)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes <= 0)
            break;
    }
}