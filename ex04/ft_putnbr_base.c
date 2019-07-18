/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljongman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 02:03:30 by ljongman          #+#    #+#             */
/*   Updated: 2019/07/18 02:06:54 by ljongman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	int				nbase;
	int				i;

	nbase = 0;
	i = 0;
	while (base[i] != '\0')
	{
		nbase++;
		i++;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		n = nbr * -1;
	}
	else
		n = nbr;
	if (n > nbase - 1)
	{
		ft_putnbr_base((n / nbase), base);
		ft_putchar((base[n % nbase]));
	}
	else
		ft_putchar((base[n % nbase]));
}

int		main(void)
{
	int		nbr;
	char	base[] = "0123456789abcdef";

	nbr = 639;
	ft_putnbr_base(nbr, base);
}
