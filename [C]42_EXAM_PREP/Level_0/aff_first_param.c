/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:39:09 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 16:59:00 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main( int argc, char *argv[])
{
	int		i;
	i = 0;

	if( argc > 1) //Arg count should be greater than 2 to run program (0-fileName, 1-stringInput)
	{
		while( argv[1][i] ) //While argv has elements (not NULL/value of 0/false)
		{
			write( 1, &argv[1][i], 1 ); //Write these elements
			i++; //Increase until run out of elements and makes the while loop false
		}
	}
	write( 1,"\n", 1 ); //After all the elements are printed or not print a new line no matter what before end of program
	return (0);
}
