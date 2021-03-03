/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschultz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:10:33 by tschultz          #+#    #+#             */
/*   Updated: 2019/01/31 18:16:44 by tschultz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ftstrcpy( char *s1, char *s2 ) //Takes in 2 strings as arguements
{
	int i; //Declare iterator variable
	i = 0; //Initialize iterator to 0

	while (s2[i]) //While s2 the source string is not at null
	{
		s1[i] = s2[i]; //Set s1 equal to the value of s2 at element number i
		i++; //Move to next element number/letter of the string until we hit NULL
	}
	s1[i] = '\0'; //i's last value is at the element Null of s2 when it broke, so we add a NULL character to the end of s1 to complete the cstring
	return(s1); //Return the name of the copied array, which is a pointer to the array's first element of the string/word of s1
}
