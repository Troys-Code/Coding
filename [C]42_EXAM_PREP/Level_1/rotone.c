/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:04:04 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 19:22:08 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main( int argc, char * argv[] ) //Program that takes in a string as arguements 
{
	int i; //Incrementer
	char letter; 

	i = 0;
	if( argc == 2 ) //If it has 2 arguements (file name + string)
	{
		while( argv[1][i] ) //While the current letter of the string at element number i is not NULL/0/False
		{
			letter = argv[1][i]; //Letter is set to the letter of the string at element number i
			if( argv[1][i] >= 'A' && argv[1][i] <= 'Y' ) //If the letter is between A and Y you can move add 1 to move to next letter
				letter++; //Letters value is one more to the right/next letter in the alphabet
			else if( argv[1][i] >= 'a' && argv[1][i] <= 'y' )
				letter++;
			else if( argv[1][i] == 'z' || argv[1][i] == 'Z' )
				letter = letter - 25; // equivelent to letter -= 25 but easier to read for noobies, this puts Z back 25 characters to A
			write( 1, &letter, 1 ); //Print the letter
			i++; //Move to the next letter by incremementing i
		}
	}
	write( 1, "\n", 1 ); //Print a new line at the end
}
