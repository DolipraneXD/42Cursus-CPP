/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:42:17 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/23 14:19:29 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float calculate(Point const &a, Point const &b, Point const &c)
{
	return ((0.5f) * (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
			+ b.getX().toFloat()*(c.getY().toFloat()-a.getY().toFloat())
			+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())));
}

bool bsp(const Point a, const Point b, const Point c, const Point tofind)
{
	float max;
	float totalsize = calculate(a, b, c);
	float  sizec = calculate(a, b, tofind);
	float  sizeb = calculate(a, tofind, c);
	float  sizea = calculate(tofind, b, c);
	if( !sizea || !sizeb || !sizec)
		return false;
	max = (sizea + sizeb + sizec);
	if (max != totalsize)
		return false;
	return true;
}
