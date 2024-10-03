# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>

// no handlign de um comando com path relativo nao e verificado se estamos a fazer a partir da diretoria presente ./ ou da parent ../ ou qualquer outra que esteja antes ou depois verificar com o vera 
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
	int		id;//maybe this should be called index
	pid_t	pid;
	char	**cmd;
	char	**path;
	char	*cmdpath;
	char	*limiter;
}		t_pipex;

void	ft_wrong_call(void)
{
	ft_putstr_fd("you should call this function like this:\
./pipex infile command1 command2 outfile\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_no_doc(t_pipex *p, int argc, char **argv)
{
	p->here_doc = 0;
	p->infile = open(argv[1], O_RDONLY);
	p->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->infile == 0 || p->outfile == 0)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
}


void	ft_parsing_pipex(t_pipex *p, int argc, char **argv)
{
	int	arg_index;
	int	index;

	index = 0;
	arg_index = 1;
	if (ft_strncmp(argv[1], "heredoc", 8) == 0)
		hellodoc(p, argc, argv);
	else
		ft_no_doc(p, argc, argv);
	p->arg = malloc(sizeof(char *) * argc);
	if (!p->arg)
		error func
	while (arg_index < argc)
	{
		p->arg[index] = ft_strdup(argv[arg_index]);
		arg_index++;
		index++;
	}
	p->arg[index] = 0;
}

void	ft_find_path(t_pipex *p, char **envp)
{
	char	*path;
	int		index;

	index = 0;
	while (envp[index++])
	{
		if(ft_strncmp(envp[index], "PATH", 4))
				path = ft_strdup(envp[index] + 5)// depois checkar aqui com prints
	}
	if (!path)
		err(p, "ERROR");
	p->path = ft_split(path, ':');
}

void	ft_access_check(t_pipex *p)
{
	if (access(p->cmdpath, F_OK) < 0)
		err_all(p, "ERROR");//needs implementation
}

void	ft_find_relative_path(t_pipex *p)
{
	int		index;
	char	*temp_path;

	index = 0;
	while (p->path++)
	{
		temp_path = ft_strjoin(p->path[index], p->cmdpath);
		if (access(temp_path, F_OK) >= 0)
		{
			p->cmdpath = ft_strdup(temp_path);
			free(temp_path);
			return ;
		}
		free(temp_path);
	}
	special_err(p, "ERROR");//needs implementation
}

void	ft_arg_setup(t_pipex *p, int cmd_index)
{
	int	str_index;

	str_index = 0;
	if(p->arg[cmd_index][str_index] == '/')
	{
		while(p->arg[cmd_index][str_index] && p->arg[cmd_index][str_index] != ' ')
			str_index++;
		p->cmdpath = ft_substr(p->arg[cmd_index], 0, str_index);
		p->cmd = ft_split(ft_strrchr(p->arg[cmd_index], '/') + 1, ' ');
		ft_access_check(p);
	}
	else
	{
		p->cmdpath = ft_strjoin("/", p->cmdpath[0]);// pretty sure this should still be done starting at the last "/" because even if its a relative path it might go into subdirectories
		p->cmd = ft_split(p->arg[cmd_index], ' ');
		ft_find_relative_path(p)
	}
}

void	ft_parent_process(t_pipex *p, int index, char **envp)
{
	if(pipe(p->pipe) == -1)
		err(p, "ERROR");
	p.id = fork();
	if (p.id == 0)// identifies child process
	{
		close(p->pipe[0]);
		if (p->id == 0)//if first time calling
		{
			dup2(p->infile, STDIN_FILENO);// this way the standard input is now the infile
			dup2(p->pipe[1], STDOUT_FILENO);// this way the standard output is the write end of the pipe
		}
		else if (p.id == p.cmdnbr - 1)//if last call
			dup2(p->outfile, STDOUT_FILENO);//this way it writes to the outfile like it was the standard out
		else//if any other call between first and last
			dup2(p->pipe[1], STDOUT_FILENO);//writes to the write end of the pipe like the standard out
		ft_arg_setup(p, index);
		execve(p->cmdpath, p->cmd, envp);
		free_all(p);
		exit(127)
	}
	close(p->pipe[1]);
	dup2(p->pipe[0], STDIN_FILENO);
	close(p->pipe[0]);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	p_values;
	int		ind;

	ind = 0;
	if (argc < 5)
		ft_wrong_call();
	ft_parsing_pipex(p_values, argc, argv);
	p.cmdnbr = argc - p.heredoc - 3;
	ft_find_path(&p, envp);
	p.id = 0;
	while(p.id++ < p.cmdnbr)
		ft_parent_process(p, p.id + p.heredoc, envp);
	close(0);
	waitpid(p->pid, NULL, 0);
	while(ind++ < p->cmdnbr - 1)
		wait(NULL);
	if (p->heredoc)
		unlink(".heredoc_temp");
	ft_free_all(&p);//missing implementation
	return (1);
}