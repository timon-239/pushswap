/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:44:03 by eboualla          #+#    #+#             */
/*   Updated: 2026/04/29 17:41:03 by eboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || (s[i - 1] == c)))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len);
	while (i < (size - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

static char	*ft_printword(const char *s, char c)
{
	size_t	len;
	char	*dest;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dest = malloc((sizeof(char)) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, len + 1);
	return (dest);
}

char	**ft_freeall(char **arr, size_t i)
{
	size_t	j;

	if (!arr)
		return (NULL);
	j = 0;
	while (j < i)
		free(arr[j++]);
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	char	**arr;

	if (!s)
		return (NULL);
	i = 0;
	arr = malloc(sizeof(*arr) * (ft_countwords(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			arr[i] = ft_printword(s, c);
			if (!arr[i++])
				return (ft_freeall(arr, i));
		}
		while (*s && *s != c)
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
