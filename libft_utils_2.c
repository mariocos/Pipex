#include "pipex.h"

char	*ft_strdup(const char *s)
{
	int		str_len;
	char	*dest;
	int		i;

	i = 0;
	str_len = ft_strlen(s) + 1;
	dest = malloc(sizeof(char) * str_len);
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (size != 0)
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}
