/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:19:28 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 16:58:47 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main( int argc, char *argv[] ) //Program that takes in a string
{
	int i; 		 //Declare increment variable
	i = 0;    		//Initialize variable to 0

	if ( argc != 2 ) //If the program doesnt have 2 parameters (file name + string)
		write( 1, "a\n", 2 ); //Just write a new line
	else
	{
		while ( argv[1][i] ) //While argv[1] which is the second param (the string) is not equal to NULL value 0
		{
			if ( argv[1][i] == 'a' ) //If that element at position i in the array is equal to the char a
			{
				write( 1, "a", 1 ); //Write that first a
				break;				//Then just break out of the while loop
			}
			i++;
		}
		write( 1, "\n", 1 ); //Print a new line no matter what
	}
	return (0);
}
