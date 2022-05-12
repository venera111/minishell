/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:09:35 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/12 21:41:06 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	cd_continue(t_shell *shell)
{
	t_envp	*tmp;
	char	*path;
	int		i;

	tmp = shell->ev;
	i = -1;
	while (++i < shell->env_count && ft_strcmp(tmp->key, "OLDPWD")) //напсиать функцию для получения ноды
		tmp = tmp->next;
	if (i != shell->env_count)
	{
		path = tmp->val;
		if (shell->tmp_cwd)
		{
			tmp->val = shell->tmp_cwd;
			free(path);
		}
	}
	getcwd(shell->cwd, sizeof("/usr/local/bin"));
	i = -1;
	tmp = shell->ev;
	while (++i < shell->env_count && ft_strcmp(tmp->key, "PWD"))
		tmp = tmp->next;
	free(tmp->val);
	tmp->val = ft_strdup(shell->cwd);       //   "/Users/qestefan/Documents/minishell"   <- "/usr/local/bin"
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
		tmp = shell->ev;
		while (++i < shell->env_count && \
		ft_strcmp(tmp->key, "HOME"))
			tmp = tmp->next;
		if (i != shell->env_count)
			chdir(tmp->val);
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