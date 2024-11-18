/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:00:22 by mariocos          #+#    #+#             */
/*   Updated: 2024/11/14 16:55:13 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int files[2])
{
	close(files[0]);
	close(files[1]);
}

void	ft_pipe(int files[2], char **argv, char **envp, int fd[2])
{
	int	pid1;
	int	pid2;

	if (pipe(fd) < 0)
		err("fail to open the pipe");
	pid1 = fork();
	if (pid1 < 0)
	{
		close_fd(fd);
		err("fail to fork for child1");
	}
	if (pid1 == 0)
		ft_child1(files, argv, envp, fd);
	pid2 = fork();
	if (pid2 < 0)
	{
		close_fd(fd);
		err("fail to fork for child2");
	}
	if (pid2 == 0)
		ft_child2(files, argv, envp, fd);
	close_fd(fd);
	close_fd(files);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	files[2];
	int	fd[2];

	if (argc != 5)
	{
		write (1, "please call as follows:", 23);
		write (1, "./pipex [infile] [cmd1] [cmd2] [outfile]\n", 41);
		exit (1);
	}
	else
	{
		files[0] = check_infile(argv);
		files[1] = check_outfile(argv, argc);
		ft_pipe(files, argv, envp, fd);
	}
}
