/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:39:39 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/09 21:58:26 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	clear(t_cmd *node)
{
	int	i;

	i = 0;
	while (node->cmnds[i])
	{
		free(node->cmnds[i]);
		i += 1;
	}
	free(node->cmnds[i]);
}