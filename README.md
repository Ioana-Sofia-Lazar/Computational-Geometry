# Computational-Geometry

Task
====

We are given 4 points in a certain order.
a) Decide if they determine a convex quadrilateral.
b) We are given a 5th point. Decide if it is in the convex hull of the 4 points.


Implemented solution
====================

a) We check whether we only have right turns (using the orientation test). If so, our quadrilateral is convex.
b) We check whether the 5th point is inside one of the 4 triangles the 4 points determine. If so, it is inside their convex hull.


Use of variables/functions
==========================

- Point -> structure for points; holds the x and y coordinates
- orientationTest(Point A, Point B, Point C) -> orientation test; if the return value is <0 then we have a right turn, otherwise it is a left turn 
- Convex(Point A, Point B, Point C, Point D) -> checks if points A, B, C, D determine a convex quadrilateral
- pInTriangle(Point A, Point B, Point C, Point P) -> checks if point P is inside triangle ABC
- apartineInfConv(Point A, Point B, Point C, Point D, Point P) -> checks if P is in the convex hull of points A, B, C, D
