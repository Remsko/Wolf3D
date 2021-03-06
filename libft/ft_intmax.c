/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:25:21 by rpinoit           #+#    #+#             */
/*   Updated: 2018/03/21 11:23:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	ft_intmax(int x, int y)
{
	return (y > x ? y : x);
}
