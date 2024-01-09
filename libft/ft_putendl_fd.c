/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:20:37 by chtang            #+#    #+#             */
/*   Updated: 2023/01/22 21:23:32 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	strcount;

	strcount = 0;
	strcount += ft_putstr_fd(s, fd);
	strcount += ft_putchar_fd('\n', fd);
	return (strcount);
}
