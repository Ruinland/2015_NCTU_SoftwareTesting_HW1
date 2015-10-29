typedef struct _Triangle {
	unsigned int edge1;
	unsigned int edge2;
	unsigned int edge3;
	} Triangle;

enum triangleType { Equilateral, Isosceles, Scalene, NotTriangle, INVALID};

triangleType judge_triangle(unsigned int e1, unsigned int e2,unsigned int e3);


