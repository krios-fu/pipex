/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:39:13 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/09 22:22:05 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2], fd_dst;
	int		status;
	char	*path;
	char 	**arg_cmd;
	
	pipe(fd);

	pid = fork();

	if(pid == -1)
		perror("Error");
	if (pid == 0)
	{
		close(fd[FD_READ_END]);
		dup2(fd[FD_WRITE_END], STDOUT_FILENO);
		close(fd[FD_WRITE_END]);
		arg_cmd = split_cmd_arg(argv[1]);
		get_path(arg_cmd[0], envp, &path);
		execve(path, arg_cmd, envp);
		
	}
	else
	{
		close(fd[FD_WRITE_END]);
		pid = fork();
		if(pid == -1)
			perror("Error");
		if (pid == 0)
		{
			fd_dst = open(argv[3],  O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
			dup2(fd[FD_READ_END], STDIN_FILENO);
			close(fd[FD_READ_END]);
			dup2(fd_dst, STDOUT_FILENO);
			arg_cmd = split_cmd_arg(argv[2]);
			get_path(arg_cmd[0], envp, &path);
			execve(path, arg_cmd, envp);

		}
		else
		{	
			close(fd[FD_READ_END]);
		}	
	}
	waitpid(pid, NULL, 0);
	waitpid(pid, NULL, 0);
}