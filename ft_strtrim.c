#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int	ft_find_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return i;
}

int	ft_find_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break;
			j++;
		}
		if (set[j] == '\0')
			break;
		i--;
	}
	return i;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	i;
	int	j;
	char	*p;

	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	i = 0;
	if (start > end)
		return NULL;
	p = malloc(sizeof(char) * (end - start + 1));
	if (p == NULL)
		return NULL;
	while (start <= end)
	{
		p[i] = s1[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return p;
}
