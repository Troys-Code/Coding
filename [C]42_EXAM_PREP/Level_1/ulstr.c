/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:04:42 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 20:10:51 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main( int argc, char *argv[] )
{
	char letter;
	int i;
	i = 0;

	if( argc == 2 )
		while( argv[1][i] )
		{
			letter = argv[1][i];
			if( argv[1][i] >= 'A' && 'Z' >= argv[1][i] )
				letter = letter + 32;
			else if( argv[1][i] >= 'a' && 'z' >= argv[1][i] )
				letter = letter - 32;
			write( 1, &letter, 1 );
			i++;
		}
	write ( 1, "\n", 1 );
}
