/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtang <chtang@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:36:46 by chtang            #+#    #+#             */
/*   Updated: 2024/01/10 02:08:44 by chtang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_freestrarray(char **ptr)
{
	while (ptr && *ptr)
	{
		free(*ptr);
		*ptr = 0;
		ptr++;
	}
	return (0);
}

int	ft_freesarray(size_t **ptr)
{
	while (ptr && *ptr)
	{
		free(*ptr);
		*ptr = 0;
		ptr++;
	}
	return (0);
}

int	ft_freelarray(long **ptr)
{
	while (ptr && *ptr)
	{
		free(*ptr);
		*ptr = 0;
		ptr++;
	}
	return (0);
}

int	ft_freeintarray(int **ptr)
{
	while (ptr && *ptr)
	{
		free(*ptr);
		*ptr = 0;
		ptr++;
	}
	return (0);
}

int	ft_freememarray(void **ptr)
{
	while (ptr && *ptr)
	{
		free(*ptr);
		*ptr = 0;
		ptr++;
	}
	return (0);
}
