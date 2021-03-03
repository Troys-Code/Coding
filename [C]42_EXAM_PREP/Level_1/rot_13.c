/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:32:27 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 18:55:39 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main( int argc, char *argv[] )
{
	int i; 			//Increment variable
	char mvup;		//Char variable that will take the value of my moved up 13 places
	char mvdown;	//Char variable that will take the value of my moved down 13 places

	i = 0; 			//Set increment variable to 0
	if( argc == 2 ) //If right number of arguements (filename + string ) do the next line of code
		while( argv[1][i] ) //While current element is not NULL the ascii value of 0
		{
			mvup = argv[1][i] + 13; //Add 13 to the elements char/ ascii value 
			mvdown = argv[1][i] - 13; //Subtract 13 to the elements char/ascii value

			if( ('A' <= argv[1][i] && 'M' >= argv[1][i] ) || ( 'a' <= argv[1][i] && 'm' >= argv[1][i] ) ) //if the letter of the string at position i is between A-M it can be moved up without passing Z
				write( 1, &mvup, 1 );
			else if( ('N' <= argv[1][i] && 'Z' >= argv[1][i] ) || ('n' <= argv[1][i] && 'z' >= argv[1][i] ) ) //If the letter of the string at position i is between N and Z it can only be moved down which works as resetting the alphabetic letter around 13 spaces after
				write( 1, &mvdown, 1 );
			else
				write( 1, &argv[1][i], 1 ); //Print letter
			i++; //Move to next element
		}
	write( 1, "\n", 1 ); //Print a new line
}
