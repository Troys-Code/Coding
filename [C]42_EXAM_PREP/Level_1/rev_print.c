/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:24:00 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 18:32:10 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main( int argc, char *argv[] ) //Program that takes in a string
{
	if( argc == 2 ) //If number of arguements is 2 (fileName + String)
	{
		int i; 					//Declare increment variable

		i = 0; 					//Initialize increment variable to 0
		while( argv[1][i] ) 	//While current element of string, is not NULL / ascii 0
			i++; 				//Increment to next element
		while(i) 				//While i is not 0 which is basically NULL
		{
			i--; 				//Decrement i
			write( 1, &argv[1][i], 1 ); //Print out the current element as it decrements to element 0
		}
	}
	write( 1, "\n", 1 ); //Write a new line 
}
