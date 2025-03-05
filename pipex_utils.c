/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:00:26 by mariocos          #+#    #+#             */
/*   Updated: 2025/03/05 13:51:46 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(int files[2], char **argv, char **envp, int fd[2])
{
	dup2(files[0], STDIN_FILENO);
	dup2 (fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
	execve("/bin/bash", (char *[]){"bash", "-c", argv[2], NULL}, envp);
	err("execve failed");
}

void	ft_child2(int files[2], char **argv, char **envp, int fd[2])
{
	dup2(fd[0], STDIN_FILENO);
	dup2 (files[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(files[0]);
	close(files[1]);
	execve("/bin/bash", (char *[]){"bash", "-c", argv[3], NULL}, envp);
	err("execve failed");
}

void	err(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
	exit (1);
}

int	check_infile(char **argv)
{
	if (access(argv[1], F_OK) == -1)
	{
		write(1, "bad infile\n", 11);
		exit (1);
	}
	if (access(argv[1], R_OK) == -1)
	{
		write(1, "bad infile\n", 11);
		exit(1);
	}
	return (open(argv[1], O_RDONLY));
}

int	check_outfile(char **argv, int argc)

{
	if (access(argv[argc - 1], F_OK) != -1)
	{
		if (access(argv[argc - 1], W_OK) == -1)
		{
			write(1, "bad outfile\n", 12);
			exit(1);
		}
	}
	return (open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777));
}
