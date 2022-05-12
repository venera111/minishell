/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:48:57 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/12 11:37:53 by qestefan         ###   ########.fr       */
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

void	free_env(t_envp **lst)
{
	t_envp	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->kval);
			if ((*lst)->key)
				free((*lst)->key);
			if ((*lst)->val)
				free((*lst)->val);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	delete_node(t_envp *node)
{
	free(node->kval);
	if (node->key)
		free(node->key);
	if (node->val)
		free(node->val);
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);	
}

void	clear_all(t_shell *shell)
{
	free_arr(shell->env_arr, shell->env_count);
	free_env(&shell->ev);
	free(shell->tmp);
	free_builtins(&shell->node);
}