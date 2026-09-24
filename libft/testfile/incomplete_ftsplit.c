/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 01:23:47 by werlim            #+#    #+#             */
/*   Updated: 2026/08/18 18:10:04 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **free_arr(char **arr, int i)
{
	int i;

	i = 0;
	while(arr[i])
		free(arr[i++]);
	return (arr);
}

static size_t	counter(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		i++;
		if (s[i] == c && s[i - 1] == c)
			i++;
		else if (s[i] == c && s[i - 1] != c)
			counter++;
	}
	if (s[i - 1] != c)
		counter++;
	return (counter);
}

static char	**f_arr(char const *s, char c, char **arr)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	start = i;
	while (s[i])
	{
		i++;
		if (s[i] == c && s[i - 1] != c)
		{
			arr[j++] = ft_substr(s, start, (size_t)(i - start));
			while (s[i] == c)
				i++;
			start = i;
		}
	}
	if (s[i] == '\0' && s[i - 1] != c)
		arr[j] = ft_substr(s, start, (size_t)(i - start));
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordcount;
	char	**arr;

	if (!s)
		return (NULL);
	wordcount = counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (arr == NULL)
		return (NULL);
	arr[wordcount] = NULL;
	if (s[0] == '\0')
		return (arr);
	else
		arr = f_arr(s, c, arr);
	return (arr);
}

/*
int main(void)
{
	char *s = "xxtestxworldxxx   crazyxxx";
	char c = 'x';
	char **arr;
	int i = 0;

	arr = ft_split(s, c);
	while (arr[i] != NULL)
	{
		printf("%s, %d\n", arr[i], i);
		i++;
	}
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}*/
