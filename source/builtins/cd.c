/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:09:35 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/15 20:14:31 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	cd_continue(t_shell *shell)
{
	t_envp	*tmp;
	char	*path;

	tmp = shell->envp;
	tmp = find_node("OLDPWD", tmp);
	path = tmp->value;
	if (shell->tmp_cwd)
	{
		tmp->value = shell->tmp_cwd;
		free(path);
	}
	getcwd(shell->arr, sizeof(shell->arr));
	tmp = shell->envp;
	tmp = find_node("PWD", tmp);
	free(tmp->value);
	tmp->value = ft_strdup(shell->arr);
}

void	cd(t_shell *shell)
{
	t_envp	*tmp;

	shell->tmp_cwd = getcwd(NULL, 0);
	tmp = NULL;
	if (shell->node.num_args == 1)
	{
		tmp = shell->envp;
		tmp = find_node("HOME", tmp);
		chdir(tmp->value);
	}
	else if ((chdir(shell->node.cmnds[1])) == -1) //парсинг готовый абсолютный/относительный(склеить с текущ или ../) путь
	{
		printf("minishell: cd: %s: %s\n", \
			shell->node.cmnds[1], strerror(errno));
		free(tmp);
		tmp = NULL;
	}
	cd_continue(shell);
}

void	pwd(t_shell *shell)
{
	printf("%s", shell->arr);
	getcwd(shell->arr, sizeof(shell->arr));
	write(1, shell->arr, ft_strlen(shell->arr)); //fd_out
	write(1, "\n", 1); //fd_out
}