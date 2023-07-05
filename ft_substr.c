/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:36:00 by skondo            #+#    #+#             */
/*   Updated: 2023/07/05 22:58:18 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ans;
	unsigned int	i;
	size_t			s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		len = 0;
	if (s_len - start < len)
		len = s_len - start;
	ans = malloc((len + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (start + i < s_len && i < len)
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		len = 0;
	if (s_len - start < len)
		len = s_len - start;
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return NULL;
	i = 0;
	while (i < len && start + i < ft_strlen(s))
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int main()
{
	char const str[256] = "libft-test-tokyo";
	printf("%s\n",ft_substr(str, 10, 100));
	printf("%s\n",ft_substr(str, 2, 10));
	printf("%s\n",ft_substr(str, 2, 10));
}
*/

