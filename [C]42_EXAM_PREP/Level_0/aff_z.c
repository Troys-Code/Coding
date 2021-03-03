/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:03:51 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 17:11:58 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main( int argc, char *argv[])
{
	int i; //Declare increment variable
	i = 0; //Initialize increment variable to 0

	if( argc != 2 ) //If the number of parameters/arguments is not 2 (file name + string)
		write( 1, "z\n", 2 ); //Just write a new line

	else //Otherwise
	{
		while( argv[1][i] ) //While the second argument the string at element i is not NULL/zero/false
		{
			if( argv[1][i] == 'z' ) //If the element at position i is equal to z
			{
				write( 1, "z", 1 ); //print a z to the screen
				break; //Then break
			}
			i++; //Increment i to move to next element until we run out of elements and break out of the while loop
		}
		write( 1, "\n", 1 ); //Print a new line at the end regardless of above conditions
	}
	return (0);
}
