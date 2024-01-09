/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:52:04 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 01:56:20 by chtang           ###   ########.fr       */
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
				write(2, "Error : Unexpected error : split failes\n", 41);
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

void	init_cmds(char ***cmds, char **av, int nb_cmd, char **paths)
{
	int		i;
	int		j;
	char	*join;

	i = -1;
	while (++i < nb_cmd)
	{
		cmds[i] = ft_split(av[i], ' ');
		j = -1;
		while (paths[++j] && cmds[i][0] && cmds[i][0][0] != -1 \
			&& !ft_strnstr(cmds[i][0], "/", ft_strlen(cmds[i][0])))
		{
			join = path_join(paths[j], cmds[i][0]);
			if (found_path(cmds[i], join))
				break ;
			free(join);
		}
		if (!cmds[i][0] || !paths[j])
			print_error(cmds[i][0], "command not found");
		if (!paths[j])
		{
			free(cmds[i][1]);
			cmds[i][1] = cmds[i][0];
			cmds[i][0] = NULL;
		}
	}
}

char	***parcing(int nb_cmd, char **av, char **env)
{
	char	**s;
	char	**paths;
	char	***cmds;

	paths = find_path(env);
	cmds = (char ***)malloc(sizeof(char **) * (nb_cmd + 1));
	if (!cmds)
	{
		write(2, "Error : Malloc() : parcing failed\n", 35);
		exit(EXIT_FAILURE);
	}
	cmds[nb_cmd] = NULL;
	init_cmds(cmds, av, nb_cmd, paths);
	s = paths;
	while (*s)
		free(*(s++));
	free(paths);
	return (cmds);
}
