#include "triangle.h"

#include <iostream>

static InvalidVars invalidEdg;

triangleType judge_triangle(unsigned int e1,
														unsigned int e2,
														unsigned int e3) {

	//Adopting the improved implementation from slides.

	unsigned int c1 = (e1 > 0) &&	(e1 <200);
	unsigned int c2 = (e2 > 0) &&	(e2 <200);
	unsigned int c3 = (e3 > 0) &&	(e3 <200);

	if ( !(c1 && c2 && c3) ) { return INVALID;
	} // which means this is not an acceptable triangle;



	else {

		if ( e1+e2<=e3 || e2+e3<=e1 || e1+e3<=e2) { return NotTriangle; } 
		else if ( (e1 == e2) && (e2 == e3)) { return Equilateral; }
		else if ( (e1 != e2) && (e2 != e3) && (e1 != e3) ) { return Scalene; }
		else { return Isosceles; }

		}
	
	}
