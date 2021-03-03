/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:19:59 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 18:23:50 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap( int *a, int *b ) //Pass in 2 integer variables by address
{
	int temp; //Place holder variable
	temp = *a; //The value of derefferenced a is assigned to temp
	*a = *b;   //The value of derefferenced b is assigned to dereffereced a
	*b = temp; //The value of temp is set to derefferenced b
}
