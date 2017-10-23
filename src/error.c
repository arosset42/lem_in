/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:05:40 by arosset           #+#    #+#             */
/*   Updated: 2017/10/19 14:29:29 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void 	ft_error_list(t_parse **tmp)
{
	ft_free_list(tmp);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void 	ft_put_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_error(t_env *env)
{
	ft_free_env(env);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	malloc_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
