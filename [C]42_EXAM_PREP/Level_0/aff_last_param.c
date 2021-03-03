/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:49:09 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 16:56:59 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char * argv[])
{
	int i; //Declare increment variable
	i = 0; //Set increment variable to 0

	if( argc > 1) //If the number of arguments is more than 1 (meaning file name + another parameter)
	{
		while( argv[argc-1][i] ) //Argc-1 would be the last parameter, so while the element at index number i is not NULL
		{
			write( 1, &argv[argc-1][i], 1 ); //Write the element
			i++; //Increment i to move to the next element in the array
		}
	}
	write(1, "\n", 1); //Print a new line at the end no matter what
	return(0);
}
