/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:18:47 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 17:19:49 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main()
{
	write( 1, "Hello World!\n", 13 );
	return(0);
}
