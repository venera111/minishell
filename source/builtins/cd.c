/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:09:35 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/12 19:29:46 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	cd(t_shell *shell)
{
	int	i;

	i = -1;
	shell->tmp_cwd = getcwd(NULL, 0);
	if (shell->node.num_args == 1)
	{
		t_envp *tmp = shell->ev;
		while (tmp)
		{
			printf("%s=%s\n%s\n", tmp->key, tmp->val, tmp->kval);
			tmp = tmp->next;
		}
	}
}