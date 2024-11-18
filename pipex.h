/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:00:28 by mariocos          #+#    #+#             */
/*   Updated: 2024/11/06 19:59:10 by mariocos         ###   ########.fr       */
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
void	ft_pipe(int *files, char **argv, char **envp, int fd[2]);
void	ft_child1(int *files, char **argv, char **envp, int fd[2]);
void	ft_child2(int *files, char **argv, char **envp, int fd[2]);
void	err(char *str);
int		check_infile(char **argv);
int		check_outfile(char **argv, int argc);
#endif
