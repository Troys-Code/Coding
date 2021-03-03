/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:49:41 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 20:00:36 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main( int argc, char *argv[] )
{
	int letter;
	int index;

	letter = 0;
	index = 0;
	if ( argc == 2 )
	{
		while ( argv[1][letter] ) //While not at null
		{
			if (argv[1][letter] >= 'a' && argv[1][letter] <= 'z') //If the character is between a - z
			{
				index = argv[1][letter] - 96;     				//Subtract 96 to get to the first number of the character code
				while ( index-- ) 								//Convert ascii character value to decimal value ('a' is 97, subtract 97-96 so index = '1' and use that index count to 'write' 1 time for 'a'.
					write( 1, &argv[1][letter], 1);
			}
			else if	(argv[1][letter] >= 'A' && argv[1][letter] <= 'Z')
			{
				index = argv[1][letter] - 64; // A = 65 subtract 64 and thats 1
				while (index--)
					write( 1, &argv[1][letter], 1 );
			}
			else
				write( 1, &argv[1][letter], 1 );
			letter++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
