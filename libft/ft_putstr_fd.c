/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:18:19 by chtang            #+#    #+#             */
/*   Updated: 2023/01/27 01:48:05 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	strcount;

	strcount = 0;
	while (s && *s)
	{
		strcount += ft_putchar_fd(*s, fd);
		s++;
	}
	return (strcount);
}
