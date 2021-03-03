/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:23:11 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 18:03:20 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		has_a_space( int i ) //Checks if the char passed in to the function is equal to the ascii value of a space
{
	if( i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ' ) //Checks for spaces by their ascii value
		return(1); 							//Has a space
	return(0); 								//Doesnt have a space
}

int main( int argc, char * argv[] ) //Program that takes in a string as arguments (use ./a.out "hello boobla" to print the first world hello)
{
	int i;
	i = 0;

	if( argc == 2 ) // If the number of arguements is not 1
	{
		while( has_a_space( (argv[1][i]) ) ) //ignores spaces before the first letter of the word/string incase of extra spaces between file name and string
			i++; 							//move to next element
		while( ! ( has_a_space( (argv[1][i]) ) ) && argv[1][i] ) //While it does not have a space print the letters/elements of the string at position i
			write( 1, &argv[1][i++], 1 );	//Increment and print the array until hit a space or run out of elements and reach NULL
	}
	write( 1, "\n", 1 ); //Write a new line no matter what at the end
	return(0);
}
