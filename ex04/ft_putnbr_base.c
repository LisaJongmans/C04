/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljongman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 02:03:30 by ljongman          #+#    #+#             */
/*   Updated: 2019/07/18 15:47:59 by ljongman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_countbase(char *base)
{
	unsigned int	nbase;
	char			rep;
	int				i;

	nbase = 0;
	while (base[nbase] != '\0')
	{
		if ((base[nbase] != '+') && (base[nbase] != '-')
		&& (base[nbase] != 127) && ((base[nbase] < 0) || (base[nbase] > 32)))
		{
			rep = base[nbase];
			nbase++;
			i = nbase;
			while (base[i] != '\0')
			{
				if (rep != base[i])
					i++;
				else
					return (0);
			}
		}
		else
			return (0);
	}
	return (nbase);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	nbase;

	nbase = ft_countbase(base);
	if (nbase > 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			n = nbr * -1;
		}
		else
			n = nbr;
		if (n > nbase - 1)
			ft_putnbr_base((n / nbase), base);
		ft_putchar(base[n % nbase]);
	}
}

int		main(void)
{
	int		nbr;
	char	*base = "01";

	nbr = -6339;
	ft_putnbr_base(nbr, base);
}
