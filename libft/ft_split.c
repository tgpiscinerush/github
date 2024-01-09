/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:22:13 by chtang            #+#    #+#             */
/*   Updated: 2023/01/19 22:57:54 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strnums(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static int	alocatestr(char const *s, char c, char **strs, size_t *idx)
{
	size_t	len;

	*idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			strs[*idx] = ft_substr(s - len, 0, len);
			if (!strs[*idx])
				return (ft_freestrarray(strs));
			(*idx)++;
		}
		while (*s && *s == c)
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	idx;
	char	**strs;
	int		ack;

	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (strnums(s, c) + 1));
	if (!strs)
		return (0);
	ack = alocatestr (s, c, strs, &idx);
	if (!ack)
		return (0);
	strs[idx] = 0;
	return (strs);
}
