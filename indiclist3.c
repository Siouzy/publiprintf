/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   indiclist3.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 16:16:06 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 18:14:18 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_x(t_spec *sp, intmax_t arg)
{
	int		i;
	char	*s;
	int		len;

	if (!(s = ft_utoa_base(arg, 16, sp->taille)))
		return (-1);
	i = 0;
	len = ft_strlen(s);
	if (sp->largmin && !ft_countchar(sp->attrib, '-'))
		i = ft_largmin(sp, len, arg);
	if (isattrib(sp->attrib))
		i = i + ft_attributs(sp, arg, len);
	if (sp->isprec)
		i = i + ft_precision(sp, len, arg);
	if (!arg && sp->isprec && !sp->precis)
		i = i - 1;
	else
		write(1, s, len);
	if (sp->largmin && ft_countchar(sp->attrib, '-'))
		i = i + ft_largmin(sp, len, arg);
	i = i + len;
	ft_strdel(&s);
	if (arg && !sp->isprec && ft_countchar(sp->attrib, '#') &&
			ft_countchar(sp->attrib, '0'))
		i = i - 2;
	return (i - sp->len);
}

int		ft_upperx(t_spec *sp, intmax_t arg)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	j = 0;
	if (!(tmp = ft_strtoupper(ft_utoa_base(arg, 16, sp->taille))))
		return (-1);
	i = 0;
	len = ft_strlen(tmp);
	if (sp->largmin > 0 && !ft_countchar(sp->attrib, '-'))
		i = ft_largmin(sp, len, arg);
	if (isattrib(sp->attrib))
		i = i + ft_attributs(sp, arg, len);
	if (sp->isprec)
		i = i + ft_precision(sp, len, arg);
	if (!arg && sp->isprec && !sp->precis)
		i = i - 1;
	else
		write(1, tmp, len);
	if (sp->largmin && ft_countchar(sp->attrib, '-'))
		i = i + ft_largmin(sp, len, arg);
	i = i + len;
	ft_strdel(&tmp);
	if (arg && !sp->precis && ft_countchar(sp->attrib, '#') &&
			ft_countchar(sp->attrib, '0'))
		i = i - 2;
	return (i - sp->len);
}

int		ft_b(t_spec *sp, intmax_t arg)
{
	int		i;
	char	*s;
	int		len;

	if (!(s = ft_itoa_base(arg, 2)))
		return (-1);
	i = 0;
	len = ft_strlen(s);
	if (sp->largmin > 0 && !ft_countchar(sp->attrib, '-'))
		i = ft_largmin(sp, len, arg);
	if (isattrib(sp->attrib))
		i = i + ft_attributs(sp, arg, len);
	if (sp->isprec)
		i = i + ft_precision(sp, len, arg);
	if (!arg && sp->isprec && !sp->precis)
		i = i - 1;
	else
		write(1, s, len);
	if (sp->largmin && ft_countchar(sp->attrib, '-'))
		i = i + ft_largmin(sp, len, arg);
	i = i + len;
	ft_strdel(&s);
	return (i - sp->len);
}

int		ft_mod(t_spec *sp, intmax_t arg)
{
	int		i;

	i = 1;
	sp->isprec = 0;
	if (sp->largmin && !ft_countchar(sp->attrib, '-'))
		i = i + ft_largmin(sp, 1, arg);
	if (isattrib(sp->attrib))
		i = i + ft_attributs(sp, arg, 1);
	write(1, "%", 1);
	if (sp->largmin && ft_countchar(sp->attrib, '-'))
		i = i + ft_largmin(sp, 1, arg);
	return (i - sp->len);
}
