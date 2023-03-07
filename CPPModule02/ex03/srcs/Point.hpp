/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:23:28 by schuah            #+#    #+#             */
/*   Updated: 2023/03/07 16:04:54 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		/* Constructor and destructor functions */
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &src);
		~Point();

		/* Copy assignation operator function */
		Point		&operator=(const Point &src);

		/* Getter functions */
		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif
