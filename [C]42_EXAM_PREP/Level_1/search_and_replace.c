/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:27:13 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 19:42:13 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main( int argc, char *argv[] ) //Program that takes in file name plus 3 strings total 4 arguements
{
	int i; //Incrementer
	i = 0; //Initialize to 0
								//Concept: "filename" "word" "letter to be replaced" "replacement letter"
	if( argc == 4 ) //If file name + 3 strings, first string is in which to replace a letter, second arguement is the letter to replace, third arguement is what letter to replace the second arguement with
	{
		if( !argv[2][1] && !argv[3][1] ) // if not out of bounds for the array, should be only 1 element/letter so it will be stored at argv[2][0] and argv[3][0] 
			while( argv[1][i] ) //While in word/string of arguement 1 and have not reached NULL
			{
				if( argv[1][i] == argv[2][0] ) //If words element number i is the same as letter at element 0 of arguement 2 the word to replace
					write( 1, &argv[3][0], 1 ); //Replace with letter element 0 of argument 3 the replacement letter arguement
				else
					write( 1, &argv[1][i], 1 ); //Else write the first character thats not the searched letter to be replaced
				i++; //increment to move to the next letter till we run out of elements
			}
	}
	write( 1, "\n", 1 ); //Print new line
	return(0);
}
