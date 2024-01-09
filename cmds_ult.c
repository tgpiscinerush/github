/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_ult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 01:47:16 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 04:10:47 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_join(char const *s1, char const *s2)
{
	char	*temp;
	char	*str;

	temp = ft_strjoin(s1, "/");
	if (!temp)
		return (FT_FAIL);
	str = ft_strjoin(temp, s2);
	if (!str)
		return (FT_FAIL);
	free(temp);
	return (str);
}
