/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:03:42 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/15 17:51:41 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_export(t_envp *envp)
{
	while (envp)
	{
		printf("declare -x %s=\"%s\"\n", envp->key, envp->value);
		envp = envp->next;
	}
}

void	export(t_shell *shell)
{
	t_envp	*a;
	char	*t;
	int		flag;

	t = NULL;
	flag = 1;
	while (flag)
	{
		shell->tmp = shell->envp;
		a = shell->tmp->next;
		flag = 0;
		while (a)
		{
			if (ft_strcmp(shell->tmp->key, a->key) > 0)
			{
				t = shell->tmp->key;
				shell->tmp->key = a->key;
				a->key = t;
				flag = 1;
			}
			shell->tmp = shell->tmp->next;
			a = a->next;
		}
	}
	print_export(shell->envp);
}
