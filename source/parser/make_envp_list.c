/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:40:02 by amoriah           #+#    #+#             */
/*   Updated: 2022/05/12 10:48:35 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp	*get_last(t_envp *head)
{
	if (head->next == NULL)
		return (head);
	while (head->next)
		head = head->next;
	return (head);
}

void	push_back(t_envp **list, t_envp **new)
{
	t_envp	*last;

	if (!(*list)) 
		*list = *new;
	else
	{
		last = get_last(*list);
		last->next = *new;
		(*new)->prev = last;
	}
}

void	create_node(t_envp **ev_list, char *env)
{
	t_envp	*new;
	new = (t_envp *)malloc(sizeof(t_envp));
	if (!new)
		ft_error(ERR_ALLOC);
	new->kval = get_kval(env);
	new->val = get_val(env);
	new->key = get_key(env);
	new->next = NULL;
	new->prev = NULL;
	push_back(ev_list, &new);
}

void	make_list(t_envp **ev_list, char **env, int ev_len)
{
	int	i;
	
	i = -1;
	*ev_list = NULL;
	while (++i < ev_len)
		create_node(ev_list, env[i]);
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