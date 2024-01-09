/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 02:10:52 by chtang            #+#    #+#             */
/*   Updated: 2023/01/27 02:44:29 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Note that a byte for the NUL should be included in size.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	dest_len;
	size_t	src_len;

	idx = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!src)
		return (0);
	if (!dst && !size)
		return (src_len);
	while (src[idx] && (idx + dest_len + 1) < size)
	{
		dst[dest_len + idx] = src[idx];
		idx++;
	}
	dst[dest_len + idx] = '\0';
	if (size < dest_len)
		return (size + src_len);
	return (dest_len + src_len);
}
