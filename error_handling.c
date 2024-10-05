#include "pipex.h"

void	free_all(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->path[i++])
		free (p->path[i]);
	free (p->path);
	i = 0;
	while (p->arg[i++])
		free (p->arg[i]);
	free (p->arg);
	close (p->infile);
	close (p->outfile);
}

void	free_here(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->path[i++])
		free(p->path[i]);
	free (p->path);
	close (p->infile);
	close (p->outfile);
}

void	err(t_pipex *p, char *s)
{
	perror (s);
	if (p->here_doc)
		free_here(p);
	else
		free_all(p);
	exit(1);
}

void	special_err(t_pipex *p, char *s)
{
	perror (s);
	free_here(p);
	exit(1);
}

void	err_all(t_pipex *p, char *s)
{
	perror (s);
	free_all(p);
	exit(1);
}
