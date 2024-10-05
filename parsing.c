#include "pipex.h"

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
				path = ft_strdup(envp[index] + 5);
	}
	if (!path)
		err(p, "ERROR");
	p->path = ft_split(path, ':');
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
	special_err(p, "ERROR");
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
		p->cmdpath = ft_strjoin("/", p->cmdpath[0]);
		p->cmd = ft_split(p->arg[cmd_index], ' ');
		ft_find_relative_path(p)
	}
}
