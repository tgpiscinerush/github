/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:22:09 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 01:08:29 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char	***cmds;
	int		fd[2];

	argc_check(ac);
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (access(av[1], R_OK) == FT_PERROR)
	{
		print_error(av[1], strerror(errno));
		av[2][0] = -1;
	}
	cmds = parcing(2, &av[2], env);
	do_pipe(cmds, env, 2, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
