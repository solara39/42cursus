#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return count + 1;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (s[size] != '\0')
		size++;
	if (start >= size || len == 0)
		return NULL;
	p = malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return NULL;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return p;
}

size_t	ft_find_index(char const *s, char c, int cnt)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	if (cnt == 0)
		return 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			nb++;
		if (nb == cnt)
		{
			i++;
			break;
		}
		i++;
	}
	return i;
}

size_t	ft_substr_len(char const *s, char c, int cnt)
{
	size_t	start;
	size_t	i;

	start = ft_find_index(s, c, cnt);
	i = start;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break;
		i++;
	}
	return i - start;
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	cnt;
	size_t	j;
	size_t	len;

	i = 0;
	cnt = ft_count_words(s, c);
	p = malloc(sizeof(char *) * (cnt + 1));
	if (p == NULL)
		return NULL;
	while (i < cnt)
	{
		len = ft_substr_len(s, c, i);
		p[i] = ft_substr(s, ft_find_index(s, c, i), len);
		if (p[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(p[j]);
				j++;
			}
			free(p);
			return NULL;
		}
		i++;
	}
	p[i] = NULL;
	return p;
}
