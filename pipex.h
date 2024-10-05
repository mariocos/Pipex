#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		here_doc;
	int		pipe[2];
	int		lastcmd;
	int		cmdnbr;
	int		in;
	int		out;
	char	**arg;
	char	*env;
	int		id;
	pid_t	pid;
	char	**cmd;
	char	**path;
	char	*cmdpath;
	char	*limiter;
}		t_pipex;
//gnl
int		ft_strlen(char *str);
int		ft_linelen(char *str);
void	ft_buffer_shift_left(char *Buffer, int move_size);
char	*ft_special_join(char *str, char *Buffer);
char	*get_next_line(int fd);
//libft_utils
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int	wordlen(char *s, char c);
int	countwords(char const *s, char c);
//libft_utils_2
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
void	ft_putstr_fd(char *s, int fd);

//pipex.c
int main(int argc, char **argv, char **envp);
void	ft_parent_process(t_pipex *p, int index, char **envp);
void	ft_access_check(t_pipex *p);
void	ft_no_doc(t_pipex *p, int argc, char **argv);
void	ft_wrong_call(void);
//parsing.c
void	ft_arg_setup(t_pipex *p, int cmd_index);
void	ft_find_relative_path(t_pipex *p);
void	ft_find_path(t_pipex *p, char **envp);
void	ft_parsing_pipex(t_pipex *p, int argc, char **argv);
//error_handling
void	err_all(t_pipex *p, char *s);
void	special_err(t_pipex *p, char *s);
void	err(t_pipex *p, char *s);
void	free_here(t_pipex *p);
void	free_all(t_pipex *p);
#endif
