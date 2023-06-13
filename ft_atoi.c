#include<stdio.h>
#include<stdlib.h>

int	ft_isdigit(const char s)
{
	if (s >= '0' && s <= '9')
		return 1;
	return 0;
}

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;
	int	result;

	index = 0;
	result = 0;
	while ((str[index] >= 0 && str[index] <= 32) || str[index] == 127)
	{
		index++;
	}
	sign = 1;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return result * sign;
}

int main()
{
	const char *str1 = "  11a";
	const char *str2 = " -aa1234";
	const char *str3 = "  +1aaa";
	const char *str4 = "a123";
	printf("%d\n",ft_atoi(str1));
	printf("%d\n",atoi(str1));
	printf("%d\n",ft_atoi(str2));
	printf("%d\n",atoi(str2));
	printf("%d\n",ft_atoi(str3));
	printf("%d\n",atoi(str3));
	printf("%d\n",ft_atoi(str4));
	printf("%d\n",atoi(str4));
}
