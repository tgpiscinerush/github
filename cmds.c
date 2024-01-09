/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:52:04 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 04:01:37 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **env)
{
	char	**paths;

	paths = NULL;
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
		{
			paths = ft_split(&((*env)[5]), ':');
			if (!paths)
			{
				ft_putendl_fd("ERROR", 2);
				exit(EXIT_FAILURE);
			}
			return (paths);
		}
		env++;
	}
	write(2, "Error : No such path exist\n", 28);
	exit(EXIT_FAILURE);
}

int	found_path(char **cmds, char *join)
{
	if (access(join, X_OK) != FT_PERROR)
	{
		free(cmds[0]);
		cmds[0] = join;
		return (FT_SUCCESS);
	}
	return (FT_FAIL);
}

int	test_access(char **cmds, char **paths, int flag)
{
	char	*join;
	int		j;

	j = 0;
	while (paths[j] && cmds[0] && flag != 1 \
			&& !ft_strnstr(cmds[0], "/", ft_strlen(cmds[0])))
	{
		join = path_join(paths[j], cmds[0]);
		if (found_path(cmds, join))
			return (j);
		free(join);
		j++;
	}
	return (j);
}

void	init_cmds(char ***cmds, char **argv, char **paths, int *flag)
{
	int		i;
	int		j;

	i = 0;
	while (i < 2)
	{
		cmds[i] = ft_split(argv[i], ' ');
		j = test_access(cmds[i], paths, flag[i]);
		if (!cmds[i][0] || !paths[j])
			print_error(cmds[i][0], "command not found");
		if (!paths[j])
		{
			free(cmds[i][1]);
			cmds[i][1] = cmds[i][0];
			cmds[i][0] = NULL;
		}
		i++;
	}
}

char	***parcing(char **argv, char **env, int *flag)
{
	char	**s;
	char	**paths;
	char	***cmds;

	paths = find_path(env);
	cmds = (char ***)malloc(sizeof(char **) * (2 + 1));
	if (!cmds)
	{
		ft_putendl_fd("ERROR", 2);
		exit(EXIT_FAILURE);
	}
	cmds[2] = NULL;
	init_cmds(cmds, argv, paths, flag);
	s = paths;
	while (*s)
		free(*(s++));
	free(paths);
	return (cmds);
}
