/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:17:08 by chtang            #+#    #+#             */
/*   Updated: 2023/01/30 17:21:12 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 += ft_strlen(s1);
	if (s2)
		len2 += ft_strlen(s2);
	str = (char *)ft_calloc((sizeof(char) * (len1 + len2 + 1)), 1);
	if (!str)
		return (0);
	if (s1)
		ft_strlcat(str, s1, len1 + 1);
	if (s2)
		ft_strlcat(str, s2, len1 + len2 + 1);
	return (str);
}
