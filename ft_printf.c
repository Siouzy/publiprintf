/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: srepelli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 16:57:06 by srepelli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 13:12:32 by srepelli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

void	ft_initialize_struct(t_spec *sp)
{
	sp->attrib = NULL;
	sp->largmin = 0;
	sp->isprec = 0;
	sp->precis = 0;
	sp->taille = NULL;
	sp->indic = '\0';
	sp->len = 0;
	sp->wclarg = 0;
	sp->wcprec = 0;
}

int		ft_isdigit(int i)
{
	if (i <= '9' && i >= '0')
		return (1);
	return (0);
}

t_spec	*ft_fill_struct(char *str)
{
	t_spec	*sp;
	int		i;

	i = 0;
	if (!(sp = malloc(sizeof(t_spec))))
		return (0);
	ft_initialize_struct(sp);
	while (ft_countchar(ATTRIB, str[i]))
		i++;
	sp->attrib = i == 0 ? ft_strnew(0) : ft_strsub(str, 0, i);
	if (str[i] == '*')
	{
		sp->wclarg = 1;
		i++;
	}
	else if (str[i] && ft_atoi(str + i))
	{
		sp->largmin = ft_atoi(str + i);
		i = i + ft_nblen(ft_atoi(str + i));
	}
	if (str[i] == '.')
	{
		sp->isprec = 1;
		if (str[i + 1] && str[i + 1] != '*')
			sp->precis = ft_atoi(str + ++i);
		else
		{
			sp->wcprec = 1;
			i = i + 2;
		}
		i = ft_isdigit(str[i]) ? i + ft_nblen(ft_atoi(str + i)) : i;
	}
	if (ft_countchar(TAILLE, str[i]))
	{
		sp->taille = ft_strsub(str, i, ft_countchar(str, str[i]));
		i = i + ft_strlen(sp->taille);
	}
	else
		sp->taille = ft_strnew(0);
	sp->indic = str[i];
	sp->len = i;
	return (sp);
}

void	bigindic(t_spec *sp)
{
	if (ft_countchar("DOU", sp->indic) == 1)
	{
		ft_strdel(&sp->taille);
		sp->taille = ft_strdup("l");
		sp->indic = ft_tolower(sp->indic);
	}
	if ((sp->indic == 'c' || sp->indic == 's') && !ft_strcmp(sp->taille, "l"))
	{
		sp->indic = ft_toupper(sp->indic);
		ft_strdel(&sp->taille);
		sp->taille = ft_strnew(0);
	}
	if (sp->indic == 'p')
	{
		ft_strdel(&sp->taille);
		sp->taille = ft_strdup("l");
	}
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		k;
	int		ret;
	int		retmp;
	va_list	va;
	char	*str;
	t_spec	*sp;

	va_start(va, format);
	i = 0;
	j = 0;
	k = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			i++;
		if (format[i] == '\0')
		{
			ft_putstr(format + j);
			va_end(va);
			return (ret + i - k);
		}
		else
			i++;
		write(1, format + j, i - j - 1);
		if (!(str = ft_strsub(format, i, ft_charstrstr(format + i, INDIC) + 1)))
			return (-1);
		sp = ft_fill_struct(str);
		bigindic(sp);
		if (sp->wclarg || sp->wcprec)
		{
			if (sp->wclarg)
				sp->largmin = va_arg(va, int);
			if (sp->wcprec)
				sp->precis = va_arg(va, int);
		}
		if (sp->indic == 's' || sp->indic == 'S')
		{
			if ((retmp = ft_indicchar(sp, va_arg(va, void *))) == -1 - sp->len)
				return (-1);
			ret = ret + retmp;
		}
		else if (ft_countchar("pdiouxXbcC%", sp->indic) == 1)
		{
			if (sp->indic == '%')
				retmp = ft_taille(sp, '%');
			else if ((retmp = ft_taille(sp, va_arg(va, intmax_t))) == -1 - sp->len)
				return (-1);
			ret = ret + retmp;
		}

		i = i + ft_strlen(str);
		ft_strdel(&str);
		j = i;
		k = k + 2;
		if (sp->indic == 'n')
			ft_n(sp, va_arg(va, intmax_t*), ret + i - k);
		ft_strdel(&sp->attrib);
		ft_strdel(&sp->taille);
		free(sp);
	}
	ft_putstr(format + j);
	ret = ret + i - k;
	va_end(va);
	return (ret);
}

/*int		main(void)
{
//	setlocale(LC_ALL, "");

	printf("\nret1 = %d\n", printf("% *.5i", 2, 42));
	printf("\nret2 = %d\n", ft_printf("% *.5i", 2, 42));
	//	printf("\nret1 = %d\n", printf("%C", 0x81000));
	//	printf("\nret2 = %d\n", ft_printf("%C", 0x81000));
	return (0);
}*/
