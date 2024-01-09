/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:33:57 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 04:17:35 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(int *pip, int valid)
{
	if (valid)
	{
		close(pip[0]);
		close(pip[1]);
	}
}

void	switch_pipes(int i, int *pipe1, int *pipe2)
{
	if (i)
	{
		close_pipe(pipe1, i > 1);
		pipe1[0] = pipe2[0];
		pipe1[1] = pipe2[1];
	}
	if (i + 1 != 2 && pipe(pipe2) == FT_PERROR)
		exit_with_fail("pipe");
}

int	create_process(int *pipe2, int i, int *file)
{
	int	pid;

	if (i == 1)
		pipe2[1] = file[1];
	pid = fork();
	if (pid == FT_PERROR)
		exit_with_fail("fork");
	return (pid);
}

void	pointing_fd(int *pipe1, int *pipe2)
{
	if (pipe1[0] == FT_PERROR)
		exit(EXIT_FAILURE);
	if (dup2(pipe1[0], STDIN_FILENO) == FT_PERROR)
		exit_with_fail("dup");
	if (dup2(pipe2[1], STDOUT_FILENO) == FT_PERROR)
		exit_with_fail("dup");
	close_pipe(pipe1, FT_SUCCESS);
	close_pipe(pipe2, FT_SUCCESS);
}

void	start_pipe(char ***cmds, char **env, int *file)
{
	int	pipe1[2];
	int	pipe2[2];
	int	pid;
	int	i;

	i = 0;
	pipe1[0] = file[0];
	while (i < 2)
	{
		switch_pipes(i, pipe1, pipe2);
		pid = create_process(pipe2, i, file);
		if (pid == 0)
		{
			pointing_fd(pipe1, pipe2);
			if (execve(cmds[i][0], cmds[i], env) == FT_PERROR && cmds[i][0])
				exit_with_fail(cmds[i][0]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	close_pipe(pipe1, FT_SUCCESS);
	while (wait(NULL) != FT_PERROR)
		;
}
