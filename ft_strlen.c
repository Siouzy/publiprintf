/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 17:44:55 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 19:31:54 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		checkmcm(wchar_t *s, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		if (sizeofwchar(s[i]) > MB_CUR_MAX)
			return (0);
		j = j + sizeofwchar(s[i]);
		i++;
	}
	return (1);
}

int		ft_wstrlen(const wchar_t *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (sizeofwchar(s[i]) == -1)
			return (-1);
		j = j + sizeofwchar(s[i]);
		i++;
	}
	return (j);
}
