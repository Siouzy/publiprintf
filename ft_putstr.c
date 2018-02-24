/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 17:41:28 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:42:39 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putwstr(wchar_t *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putwchar(s[i]);
			i++;
		}
	}
}
