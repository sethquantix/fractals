/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 05:38:35 by cchaumar          #+#    #+#             */
/*   Updated: 2017/03/21 05:39:24 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

void	die(const char *format, int exit_code, ...)
{
	va_list	va;

	va_start(va, exit_code);
	ft_vaprintf(format, va);
	va_end(va);
	exit(exit_code);
}
