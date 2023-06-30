#include<stdio.h>
#include<stdlib.h>

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

int	main()
{
	char const str1[256] = "12345678900987654321";
	char const str2[256] = "12345678901110987654321";
	char const str3[256] = "123456789009876543221";
	char const set[256] = "123";
	printf("%s\n",ft_strtrim(str1,set));
	printf("%s\n",ft_strtrim(str2,set));
	printf("%s\n",ft_strtrim(str3,set));
}
