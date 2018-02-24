/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_attributs.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 17:08:33 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 17:52:27 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*doubleattrib(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		if (str[i] && !ft_countchar(dest, str[i]))
		{
			dest[j] = str[i];
			j++;
			i++;
		}
		else
			i++;
	}
	ft_strdel(&str);
	j++;
	dest[j] = '\0';
	return (dest);
}

int		ft_attributs(t_spec *sp, intmax_t arg, int len)
{
	int		(*f[5])(t_spec *, intmax_t, int i);
	int		i;
	int		j;

	j = 0;
	i = 0;
	f[0] = ft_zero;
	f[2] = ft_space;
	f[3] = ft_plus;
	f[4] = ft_sharp;
	sp->attrib = doubleattrib(sp->attrib);
	while (sp->attrib[j] != '\0')
	{
		if (sp->attrib[j] != '-')
			i = i + f[ft_charpos(ATTRIB, sp->attrib[j])](sp, arg, len);
		j++;
	}
	return (i);
}
