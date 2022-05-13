/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:48:57 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/13 16:49:45 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_builtins(t_cmd *node)
{
	int	i;

	i = -1;
	while (++i < node->num_args)
		free(node->cmnds[i]);
	free(node->cmnds);
}

void free_arr(char **arr, int arr_len)
{
	if (arr)
	{		
		while (arr_len >= 0)
		{
			if (arr[arr_len])
				free(arr[arr_len]);
			arr_len--;
		}
		free(arr);
		arr = NULL;
	}
}

void	free_env(t_envp *envp)
{
	t_envp	*tmp;

	while (envp && envp->next)
	{
		tmp = envp;
		envp = envp->next;
		ft_memdel(tmp->str);
		ft_memdel(tmp);
	}
	ft_memdel(envp->str);
	ft_memdel(envp);
}

void	clear_all(t_shell *shell)
{
	free_arr(shell->env_arr, shell->env_count);
	free_env(shell->envp);
	free(shell->tmp);
	free_builtins(&shell->node);
}