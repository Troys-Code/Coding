/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:32:50 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 20:50:35 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //Needed for PrintF
#include <stdlib.h> //Needed for Atoi

int main( int argc, char *argv[] )
{
	if( argc == 4 )
	{
		if( argv[2][0] == '+' )
			printf( "%d", ( atoi(argv[1]) + atoi(argv[3]) ) );
		if( argv[2][0] == '-' )
			printf( "%d", ( atoi(argv[1]) - atoi(argv[3]) ) );
		if( argv[2][0] == '*' )
			printf( "%d", ( atoi(argv[1]) * atoi(argv[3]) ) );
		if( argv[2][0] == '/' )
			printf( "%d", ( atoi(argv[1]) / atoi(argv[3]) ) );
		if( argv[2][0] == '%' )
			printf( "%d", ( atoi(argv[1]) % atoi(argv[3]) ) );
	}
	printf("\n");
}
