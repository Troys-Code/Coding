/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:17:06 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 18:19:40 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen( char *str )
{
	int i;

	i = 0;
	while( str[i] ) //while string at element number i is not NULL aka the value 0 which makes it false
		i++; //move to next element until we reach null.
	return( i ); //Return the number of elements in the array based on 0-NULL 
}	
