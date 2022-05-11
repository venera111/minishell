/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:52:06 by qestefan          #+#    #+#             */
/*   Updated: 2022/05/11 19:38:18 by qestefan         ###   ########.fr       */
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
	int		num_args;
	char	**cmnds;
}				t_cmd;

/*
** builtins
*/
int		echo(t_cmd *node);

/*
** clear
*/
void	clear(t_cmd *node);

#endif