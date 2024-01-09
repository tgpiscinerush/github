/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:22:09 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 04:03:35 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	***cmds;
	int		fd[2];
	int		flag[2];

	argc_check(argc);
	flag[0] = 0;
	flag[1] = 0;
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (access(argv[1], R_OK) == FT_PERROR)
	{
		print_error(argv[1], strerror(errno));
		flag[0] = 1;
	}
	cmds = parcing(&argv[2], env, flag);
	do_pipe(cmds, env, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
