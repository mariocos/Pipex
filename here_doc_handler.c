#include "pipex.h"

void	heredocfill(int tempfd, char **argv)
{
	char *tmp;
	char *buf;

	tmp = ft_strjoin(argv[2], "/n");
	while (1)
	{
		write(1, "pipe to heredoc> ", 17);
		buf = get_next_line(0);
		if (buf)
		{
			if (ft_strncmp(buf, tmp, ft_strlen(tmp)) == 0)
				break ;
			write(tempfd, buf, ft_strlen(buf));
			free (buf);
		}
		else
			break ;
	}
	free (tmp);
	if (buf)
		free (buf);
}

void	hellodoc(t_pipex *p, int argc, char **argv)
{
	int	tempfd;

	if (argc < 6)
		ft_wrong_call();
	p->here_doc = 1;
	tempfd = open(".heredoc_temp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	p->outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (tempfd < 0 || p->outfile < 0)
	{
		perror("Error");
		exit(1);
	}
	heredocfill(tempfd, argv);
	close(tempfd);
	p->infile = open(".heredoc_temp", O_RDONLY);
	if (p->infile < 0)
	{
		unlink (".heredoc_temp");
		exit(1);
	}
}

char	*ft_strrchr(const char *s, int c)
{
	char	hold;
	char	*ret;

	hold = c;
	ret = 0;
	while (*s)
	{
		if (*s == hold)
			ret = (char *)s;
		s++;
	}
	if (*s == hold)
		ret = (char *)s;
	return ((char *)ret);
}
