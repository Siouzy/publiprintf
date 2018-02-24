/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 17:49:09 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 13:45:51 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*tronc;

	i = 0;
	tronc = (char*)malloc(sizeof(char) * (len + 1));
	if (tronc == 0)
		return (NULL);
	if (s && len != 0)
	{
		while (i < len)
			tronc[i++] = s[start++];
		tronc[i] = '\0';
		return (tronc);
	}
	return (tronc);
}
