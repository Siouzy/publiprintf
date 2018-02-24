/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   isattrib.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 13:21:56 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 12:08:39 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		isattrib(char *s)
{
	char *att;

	att = ft_strdup("#0- +");
	if (ft_strcmp("\0", s) == 0)
		return (0);
	if (ft_charstrstr(att, s) > 0 || ft_countchar(att, s[0]) > 0)
		return (1);
	return (0);
}

int		isindic(char c)
{
	char *indic;

	indic = ft_strdup("scpdDiouxXbSCDOU%");
	if (ft_countchar(indic, c) > 0)
		return (1);
	return (0);
}

int		isindicint(char c)
{
	char	*indic;
	int		i;

	i = 0;
	indic = ft_strdup("pdiouxXbcC%");
	if (ft_countchar(indic, c) > 0)
	{
		while (indic[i] != c && indic[i] != '\0')
			i++;
		return (i + 1);
	}
	return (0);
}
