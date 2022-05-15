/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:47:16 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/15 18:41:17 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	write_lines(t_cmd *node, int i, int f)
{
	char	*line;

	while (i < node->num_args)
	{
		line = node->cmnds[i];
		ft_putstr_fd(line, 1); //fd_out
		if (i + 1 != node->num_args)
			write(1, " ", 1); //fd_out
		i++;
	}
	if (!f)
		write(1, "\n", 1); //fd_out
}

static int	check_line(char *line, int i)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[0] != '-' || line[1] != 'n')
			return (i);
		if (j >= 1)
		{
			if (line[j] != 'n' && line[j] != '-')
				return (i);
			if (line[j - 1] == 'n' && line[j] == '-')
				return (i);
		}
		j++;
	}
	return (0);
}

static int	has_delete_nline(t_cmd *node)
{
	int		i;
	int		ret;
	char	*line;

	i = 1;
	while (node->cmnds[i])
	{
		line = node->cmnds[i];
		ret = check_line(line, i);
		if (ret)
			return (ret);
		i++;
	}
	return (-1);
}

int	echo(t_cmd *node)
{
	int	i;
	int	f;

	i = 1;
	f = 0;
	if (node->num_args == 1)
	{
		write(1, "\n", 1); //ft_out
		return (0);
	}
	else if (node->cmnds[1][0] == '-' && node->cmnds[1][1] == 'n' \
		&& node->num_args == 2 && !node->cmnds[1][2])
		return (0);
	else if (node->cmnds[1][0] == '-' && node->cmnds[1][1] == 'n')
	{
		i = has_delete_nline(node);
		if (i != 1)
			f = 1;
	}
	if (i < 0)
		i = 1;
	write_lines(node, i, f);
	return (0);
}
