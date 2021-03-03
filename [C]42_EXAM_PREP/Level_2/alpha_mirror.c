/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:21:49 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 20:29:26 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main( int argc, char *argv[] )
{
	int i;
	char ltr;

	i = 0;
	if( argc == 2 )
		while( argv[1][i] ) //While the letter of the string at element i is not NULL loop
		{
			ltr = argv[1][i];
			if( 'A' <= argv[1][i] && 'Z' >= argv[1][i] )
				ltr = 'Z' - argv[1][i] + 'A';
			if( 'a' <= argv[1][i] && 'z' >= argv[1][i] )
				ltr = 'z' - argv[1][i] + 'a';
			write( 1, &ltr, 1 );
			i++;
		}
	write( 1, "\n", 1 );
}
