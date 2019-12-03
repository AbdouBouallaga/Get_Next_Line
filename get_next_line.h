/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:10:33 by babdelka          #+#    #+#             */
/*   Updated: 2019/06/15 14:12:18 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 64
# define FD_MAX 4864

# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
