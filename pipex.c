#include "pipex.h"

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

void	ft_access_check(t_pipex *p)
{
	if (access(p->cmdpath, F_OK) < 0)
		err_all(p, "ERROR");//needs implementavoid	ft_putstr_fd(char *s, int fd)
}

void	ft_parent_process(t_pipex *p, int index, char **envp)
{
	if(pipe(p->pipe) == -1)
		err(p, "ERROR");
	p->id = fork();
	if (p->id == 0)// identifies child process
	{
		close(p->pipe[0]);
		if (p->id == 0)//if first time calling
		{
			dup2(p->infile, STDIN_FILENO);// this way the standard input is now the infile
			dup2(p->pipe[1], STDOUT_FILENO);// this way the standard output is the write end of the pipe
		}
		else if (p->id == p->cmdnbr - 1)//if last call
			dup2(p->outfile, STDOUT_FILENO);//this way it writes to the outfile like it was the standard out
		else//if any other call between first and last
			dup2(p->pipe[1], STDOUT_FILENO);//writes to the write end of the pipe like the standard out
		ft_arg_setup(p, index);
		execve(p->cmdpath, p->cmd, envp);
		free_all(p);
		exit(127);
	}
	close(p->pipe[1]);
	dup2(p->pipe[0], STDIN_FILENO);
	close(p->pipe[0]);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	p;
	int		ind;

	ind = 0;
	if (argc < 5)
		ft_wrong_call();
	ft_parsing_pipex(&p, argc, argv);
	p.cmdnbr = argc - p.here_doc - 3;
	ft_find_path(&p, envp);
	p.id = 0;
	while(p.id++ < p.cmdnbr)
		ft_parent_process(&p, p.id + p.here_doc, envp);
	close(0);
	waitpid(p.pid, NULL, 0);
	while(ind++ < p.cmdnbr - 1)
		wait(NULL);
	if (p.here_doc)
		unlink(".heredoc_temp");
	free_all(&p);//missing implementation
	return (1);
}
