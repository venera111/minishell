/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:38:24 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/12 11:38:34 by qestefan         ###   ########.fr       */
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
		echo(node);
}

static void	builtins(t_shell *shell, int argc, char **argv)
{
	shell->node.cmnds = split_argv(argc, argv);
	shell->node.num_args = argc - 1;
	check_cmd(&shell->node);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		shell;

	(void)argc;
	(void)argv;
	shell.env_arr = NULL;
	shell.env_count = count_len_arr(envp);
	shell.env_arr = make_env_arr(envp, shell.env_count);
	shell.ev = malloc(sizeof(t_envp *));
	if (!shell.ev)
		ft_error(ERR_ALLOC);
	shell.tmp = shell.ev;
	make_list(&shell.ev, envp, shell.env_count);
	builtins(&shell, argc, argv);
	clear_all(&shell);
	return (0);
}