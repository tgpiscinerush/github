/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:06:03 by chtang            #+#    #+#             */
/*   Updated: 2023/01/06 19:12:14 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Find the first occurrence of find in s, where the search is limited to the
//first slen characters of s.
char	*ft_strnstr(const char	*s, const char *find, size_t slen)
{
	size_t	idx;
	size_t	find_len;

	idx = 0;
	find_len = ft_strlen(find);
	if (find_len == 0)
		return ((char *)s);
	if (find_len > slen)
		return (0);
	while (s[idx] && idx < slen)
	{
		if (ft_strncmp(s + idx, find, find_len) == 0)
			return ((char *)s + idx);
		idx++;
		if (slen - idx < find_len)
			return (0);
	}
	return (0);
}
