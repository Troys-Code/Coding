/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:06:43 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 20:03:00 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr( char *str ) //Function that takes in a string
{
	int i;
	i = 0;

	while( str[i] ) //While string value is not NULL the ascii value 0/False
		write( 1, &str[i++], 1 ); //Print element and incremenet until untill we break out of the while loop at NULL
}
