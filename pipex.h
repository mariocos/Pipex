/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:00:28 by mariocos          #+#    #+#             */
/*   Updated: 2025/03/05 13:49:04 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

void	close_fds(int fd[2]);
void	close_files(int files[2]);
void	ft_pipe(int files[2], char **argv, char **envp, int fd[2]);
void	ft_child1(int files[2], char **argv, char **envp, int fd[2]);
void	ft_child2(int files[2], char **argv, char **envp, int fd[2]);
void	err(char *str);
int		check_infile(char **argv);
int		check_outfile(char **argv, int argc);
#endif
