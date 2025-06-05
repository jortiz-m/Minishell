/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:09:48 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/06/05 14:10:42 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_export_case(t_minishell *minishell, char *arg)
{
	char	*var_name;

	var_name = get_envp_var_name(arg);
	if (!ft_strchr(arg, '='))
		export_no_equal(minishell, arg);
	else
	{
		if (ft_strchr(arg, '+') && *(ft_strchr(arg, '+') + 1) == '=')
		{
			minishell->envp = export_plus_equal(minishell->envp, arg, var_name);
			minishell->declare_matrix = export_plus_equal
				(minishell->declare_matrix, arg, var_name);
		}
		else
		{
			minishell->envp = export_equal(minishell->envp, arg, var_name);
			minishell->declare_matrix = export_equal
				(minishell->declare_matrix, arg, var_name);
		}
	}
	free(var_name);
}

void	ft_export(t_minishell *minishell)
{
	int		i;

	if (matrix_len(minishell->input_matrix) == 1)
	{
		show_declare_matrix(minishell->declare_matrix);
		return;
	}
	i = 1;
	while (minishell->input_matrix[i])
	{
		if (!valid_symbols(minishell->input_matrix[i]))
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(minishell->input_matrix[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			minishell->exit_status = 1;
			i++;
			continue ;
		}
		handle_export_case(minishell, minishell->input_matrix[i]);
		i++;
	}
}
