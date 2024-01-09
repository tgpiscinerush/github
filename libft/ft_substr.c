/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:07:35 by chtang            #+#    #+#             */
/*   Updated: 2023/01/19 02:45:14 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	strlen;
	unsigned int	idx;
	char			*substr;

	idx = 0;
	if (!s)
		return (0);
	strlen = ft_strlen(s);
	idx = 0;
	if (start > strlen)
		start = strlen;
	if (len > strlen - start)
		len = strlen - start;
	substr = (char *)ft_calloc(sizeof(char) * (len + 1), 1);
	if (!substr)
		return (0);
	while (s[start + idx] && idx < len)
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = 0;
	return (substr);
}
