/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:38:24 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/15 18:12:19 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	count_len_arr(char **arr)
{
	int	i;

	i = 0;
	while(*(arr + i))
		i++;
	return(i);
}

char	**make_env_arr(char **src, int len_src)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_calloc((len_src + 1), sizeof(char *));
	if (!res)
		ft_error(ERR_ALLOC);
	while (*(src + i))
	{
		res[i] = ft_strdup(src[i]);
		i++;
	}
	i = 0;
	return (res);
}

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

static void	builtins(t_shell *shell, int argc, char **argv)
{
	char	*cmd;

	shell->node.cmnds = split_argv(argc, argv);
	shell->node.num_args = argc - 1;
	cmd = shell->node.cmnds[0];
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		echo(&shell->node);
	else if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		cd(shell);
	else if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		pwd(shell);
	else if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		export(shell);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		shell;

	(void)argc;
	(void)argv;
	shell.env_arr = NULL;
	shell.env_count = count_len_arr(envp);
	shell.env_arr = make_env_arr(envp, shell.env_count); //не используется
	shell.envp = malloc(sizeof(t_envp *));
	if (!shell.envp)
		ft_error(ERR_ALLOC);
	shell.start = shell.envp;
	envp_init(&shell, envp);

	// распечатать переменные окружения и сравнить с оригиналом
	// t_envp *tmp = shell.envp;
	// while (tmp)
	// {
	// 	if (!(ft_strcmp(*envp, ft_strjoin(tmp->key, ft_strjoin("=", tmp->value)))))
	// 		printf("%s\n",tmp->str);
	// 	else
	// 		printf("error\n");
	// 	tmp = tmp->next;
	// 	envp++;
	// }

	builtins(&shell, argc, argv);

	//распечать переменные окружения после export
	// t_envp *list;
	// list = shell.envp;
	// while (list)
	// {
	// 	printf("%s=%s\n", list->key, list->value);
	// 	list = list->next;
	// }
	// clear_all(&shell);
	return (0);
}