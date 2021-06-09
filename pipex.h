/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:58:56 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/09 19:52:38 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define	FD_READ_END		0
#define	FD_WRITE_END	1

/* Search path*/

short	get_path(char *cmd, char *envp[], char **f_path);

/* Utils */

void	free_matrix(char **matrix);
char	**split_cmd_arg(char *argv);
#endif
