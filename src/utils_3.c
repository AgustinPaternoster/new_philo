/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <apaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:47:39 by apaterno          #+#    #+#             */
/*   Updated: 2024/11/28 17:40:28 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_exit(char *msg, int exit_code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(exit_code);
}
