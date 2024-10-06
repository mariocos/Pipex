#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# define BUFFER_SIZE 42
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
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char const *s, char c);
int	wordlen(char *s, char c);
int	countwords(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
//libft_utils_2
char	*ft_strdup(char *s);
void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strcat(char *dst, char *src, char	*ret);
char	*ft_strjoin(char *s1, char *s2);
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
//heredoc
void	heredocfill(int tempfd, char **argv);
void	hellodoc(t_pipex *p, int argc, char **argv);
char	*ft_strrchr(const char *s, int c);
#endif
