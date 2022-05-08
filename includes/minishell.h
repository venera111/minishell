/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:52:06 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/08 19:39:56 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libft.h>

typedef struct	s_cmd
{
	int		fd[2];
	int		fd_in;
	int		fd_out;
	char	**cmnds;
}				t_cmd;

/*
** builtins
*/
int	echo(t_cmd *node);

#endif