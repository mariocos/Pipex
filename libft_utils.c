#include "pipex.h"


int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == c)
			i++;
	}
	return (count);
}

int	wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**ret;
	int		i;

	if (!s)
		return (0);
	wordcount = countwords(s, c);
	ret = malloc(sizeof(char *) * (wordcount + 1));
	if (!ret)
		return (0);
	i = 0;
	while (wordcount-- > 0)
	{
		while (*s == c && *s)
			s++;
		ret[i] = ft_substr((char *)s, 0, wordlen((char *)s, c));
		if (!ret[i])
			return (0);
		s += wordlen((char *)s, c);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}