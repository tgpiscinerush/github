/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 01:07:02 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 01:43:19 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argc_check(int argc)
{
	if (argc != 5)
	{
		ft_putendl_fd("argc error", 2);
		exit(1);
	}
}

void	exit_with_fail(char *str)
{
	char	*msg;
	size_t	fd;

	fd = 2;
	ft_putstr_fd("shell : ", fd);
	msg = strerror(errno);
	write(2, msg, ft_strlen(msg));
	ft_putstr_fd(": ", fd);
	ft_putstr_fd(str, fd);
	write(2, " \n", 2);
	exit(EXIT_FAILURE);
}

void	print_error(char *str, char *msg)
{
	size_t	fd;

	fd = 2;
	ft_putstr_fd("shell : ", fd);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd(": ", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\n", fd);
}

int	not_a_path(char *str)
{
	if (!ft_strnstr(str, "/", ft_strlen(str)))
		return (FT_SUCCESS);
	return (FT_FAIL);
}
