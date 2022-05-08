/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:47:16 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/08 19:45:50 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	echo(t_cmd *node)
{
	if (!node->cmnds[1])
		write(1, "\n", 1);
	else if (node->cmnds[1][0] == '-' && node->cmnds[1][1] == 'n' \
		&& !node->cmnds[2])
		return (0);
	else
	{
		printf("there are three argum\n");
	}
	return (0);
}яй
