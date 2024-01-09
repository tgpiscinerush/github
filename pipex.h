/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:22:47 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 03:21:34 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>

void	argc_check(int argc);
void	print_error(char *str, char *msg);
char	*path_join(char const *s1, char const *s2);
void	exit_with_fail(char *s);
int		not_a_path(char *str);
char	***parcing(char **av, char **env, int flag);
void	do_pipe(char ***cmds, char **env, int *in_out_file);

#endif
