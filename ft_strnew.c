/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 17:47:34 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 13:47:17 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char		*s;
	size_t		i;

	i = 0;
	s = (char*)malloc(sizeof(char) * (size + 1));
	if (s)
	{
		while (i <= size + 1)
		{
			s[i] = '\0';
			i++;
		}
		return (s);
	}
	return (NULL);
}
