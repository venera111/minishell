/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:38:24 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/08 19:40:33 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**split_argv(int argc, char **argv)
{
	char	**args;
	int		i;
	int		j;
	int		len;

	args = (char **)malloc(sizeof(char *) * (argc - 1));
	args[argc - 1] = NULL;
	i = -1;
		while (++i < (argc - 1))
	{
		len = ft_strlen(argv[i+1]);
		args[i] = (char *)malloc(sizeof(char) * (len + 1));
		args[i][len] = '\0';
		j = -1;
		while (++j < len)
			args[i][j] = argv[i+1][j];
	}
	return (args);
}

void	check_cmd(t_cmd *node)
{
	char	*cmd;
	
	cmd = node->cmnds[0];
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		echo(node); //написать реализацию
}

int	main(int argc, char **argv)
{
	t_cmd	node;

	node.cmnds = split_argv(argc, argv);
	check_cmd(&node);
	// while (*node.cmnds)
	// 	printf("%s ", *node.cmnds++);
	return (0);
}