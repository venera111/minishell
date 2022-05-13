/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:09:35 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/13 16:18:41 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	cd_continue(t_shell *shell)
{
	t_envp	*tmp;
	char	*path;
	int		i;

	tmp = shell->envp;
	i = -1;
	while (++i < shell->env_count && ft_strcmp(tmp->key, "OLDPWD")) //напсиать функцию для получения ноды
		tmp = tmp->next;
	if (i != shell->env_count)
	{
		path = tmp->value;
		if (shell->tmp_cwd)
		{
			tmp->value = shell->tmp_cwd;
			free(path);
		}
	}
	getcwd(shell->arr, sizeof(shell->arr));
	i = -1;
	tmp = shell->envp;
	while (++i < shell->env_count && ft_strcmp(tmp->key, "PWD"))
		tmp = tmp->next;
	free(tmp->value);
	tmp->value = ft_strdup(shell->arr);       //   "/Users/qestefan/Documents/minishell"   <- "/usr/local/bin"
}

void	cd(t_shell *shell)
{
	int		i;
	t_envp	*tmp;

	i = -1;
	shell->tmp_cwd = getcwd(NULL, 0);
	tmp = NULL;
	if (shell->node.num_args == 1)
	{
		tmp = shell->envp;
		while (++i < shell->env_count && \
		ft_strcmp(tmp->key, "HOME"))
			tmp = tmp->next;
		if (i != shell->env_count)
			chdir(tmp->value);
		// free(shell->tmp_cwd); //убрать очистку
	}
	else if ((chdir("/usr/local/bin")) == -1) //парсинг готовый абсолютный/относительный(склеить с текущ или ../) путь
	{
		printf("minishell: cd: %s: %s\n", \
			shell->env_arr[1], strerror(errno));
		free(tmp);
		tmp = NULL;
		// free(shell->tmp_cwd); //убрать очистку
	}
	cd_continue(shell);
}

void	pwd(t_shell *shell)
{
	printf("%s", shell->arr);
	getcwd(shell->arr, sizeof(shell->arr));
	write(1, shell->arr, ft_strlen(shell->arr));
	write(1, "\n", 1);
}