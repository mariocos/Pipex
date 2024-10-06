#include "pipex.h"

char	*ft_strdup(char *s)
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

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int				ret;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	ret = 0;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && *str1 != '\0' && --n > 0)
	{
		str1++;
		str2++;
	}
	ret = *str1 - *str2;
	return (ret);
}

char	*ft_strcat(char *dst, char *src, char	*ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		ret[i] = dst[i];
		i++;
	}
	while (src[j] != '\0')
		ret[i++] = src[j++];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(s1_len + s2_len + 1);
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	ft_strcat(s1, s2, ret);
	return (ret);
}