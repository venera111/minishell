/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:48:57 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/15 20:01:23 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_builtins(t_cmd *node)
{
	int	i;

	i = -1;
	while (++i < node->num_args)
		free(node->cmnds[i]);
	free(node->cmnds);
}

static void	free_env(t_envp *envp)
{
	t_envp	*tmp;

	while (envp && envp->next)
	{
		tmp = envp;
		envp = envp->next;
		ft_memdel(tmp->value);
		ft_memdel(tmp->str);
		ft_memdel(tmp->key);
		ft_memdel(tmp);
	}
	ft_memdel(envp->value);
	ft_memdel(envp->str);
	ft_memdel(envp->key);
	ft_memdel(envp);
}

void	clear_all(t_shell *shell)
{
	free_env(shell->envp);
	free_builtins(&shell->node);
}