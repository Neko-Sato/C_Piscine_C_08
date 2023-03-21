/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:58:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/21 12:00:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

void	print_num(unsigned int nb)
{
	char	c;

	if (nb == 0)
		return ;
	print_num(nb / 10);
	c = '0' + (nb % 10);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (!nb)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	print_num(nb);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		write(1, str + i++, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		write(1, "\n", 1);
		par++;
	}
}
