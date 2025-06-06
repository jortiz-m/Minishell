/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:40:32 by antonimo          #+#    #+#             */
/*   Updated: 2025/06/05 14:31:33 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_minishell *minishell)
{
	if (matrix_len(minishell->input_matrix) != 1)
	{
		ft_putstr_fd("This command executes without arguments\n",
			2);
		minishell->exit_status = 1;
		return ;
	}
	print_matrix(minishell->envp);
}
