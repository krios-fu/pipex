/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:56:22 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/09 19:30:56 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while(matrix[i])
		free(matrix[i++]);
	free(matrix);	
}

short	get_path(char *cmd, char *envp[], char **f_path)
{
	char	**paths;
	char	*path;
	char	*path_cmd;
	int		i;
	int		fd;
	
	i = 0;
	paths = ft_split(ft_strchr(envp[6], '/') , ':');
	while(paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		fd = open(path_cmd, O_RDONLY);
		if(fd >= 0)
		{
			*f_path = path_cmd;
			free_matrix(paths);
			close(fd);
			return(i);
		}
		free(path_cmd);
		i++;
	}
	free_matrix(paths);
	return (fd);
}

char	**split_cmd_arg(char *argv)
{
	char **cmd_arg;

	cmd_arg = ft_split(argv, ' ');
	return (cmd_arg);	
}