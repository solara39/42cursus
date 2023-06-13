#include<stdio.h>
#include<string.h>

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

char *ft_strnstr(const void *haystack, const void *needle, size_t len)
{
	size_t	i;
	size_t	j;
	const char *p;
	const char *q;

	p = haystack;
	q = needle;
	if (ft_strlen(q) == 0)
		return (char *)p;
	if (ft_strlen(q) > len)
		return NULL;
	i = 0;
	while (i < len - ft_strlen(q) && p[i] != '\0')
	{
		j = 0;
		while (p[j + i] == q[j] && q[j] != '\0')
		{
			j++;
			if (j == ft_strlen(q))
				return (char*)&p[i];
		}
		i++;
	}
	return NULL;
}

int main()
{
	const char *str1 = "abcdefghij";
	const char *str2 = "def";
	printf("%s\n",ft_strnstr(str1, str2, 10));
	printf("%s\n",strnstr(str1, str2, 10));
	printf("%s\n",ft_strnstr(str1, str2, 5));
	printf("%s\n",strnstr(str1, str2, 5));
	printf("%s\n",ft_strnstr(str1, NULL, 0));
	printf("%s\n",strnstr(str1, NULL, 0));
}
