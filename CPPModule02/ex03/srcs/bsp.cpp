/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:46:10 by schuah            #+#    #+#             */
/*   Updated: 2023/03/07 16:14:03 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Returns true if the point is on the line, else false */
static bool	on_line(Point const a, Point const b, Point const p)
{
	Fixed	m, c, dx, dy;

	dx = b.getX() - a.getX();
	dy = b.getY() - a.getY();
	m = dy / dx;
	c = a.getY() - a.getX() * m;
	return (p.getY() == (m * p.getX() + c))
}	

/* Area of a triangle: [Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)] / 2
** Return absolute value because area cannot be <= 0 */
static float get_area(Point const a, Point const b, Point const c)
{
	float	area;

	area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
			+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
			+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
	return (area >= 0 ? area : (area * -1));
}

/* Returns true if area of PAB, PBC and PAC is equal to ABC
** Returns flase if area of PAB, PBC and PAC are 0 and point is not at 0, 0 */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	t_abc, t_pab, t_pbc, t_pac;

	t_abc = get_area(a, b, c);
	t_pab = get_area(point, a, b);
	t_pbc = get_area(point, b, c);
	t_pac = get_area(point, a, c);
	if (on_line(a, b, point) || on_line(b, c, point) || on_line(a, c, point))
		return (false);
	return (t_pab + t_pbc + t_pac == t_abc ? true : false);
}
