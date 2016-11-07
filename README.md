# Computational-Geometry

*Author: Ioana Pascu*   
*Created: 06.11.2016*

Task
---

We are given 4 points in a certain order.  
a) Decide if they determine a convex quadrilateral.  
b) We are given a 5th point. Decide if it is in the convex hull of the 4 points.  


Implemented solution
-------------------

a) We check whether we only have right or left turns (using the orientation test). If so, our quadrilateral is convex.  
b) We check whether the 5th point is inside one of the 4 triangles the 4 points determine or if it is on one of the sides or if it is one of the 4 points. If so, it is in their convex hull.  


Use of variables/functions
--------------------------

- **Point** -> structure for points; holds the x and y coordinates
- **orientationTest(Point A, Point B, Point C)** -> orientation test; if the return value is <0 then we have a right turn, otherwise it is a left turn 
- **Convex(Point A, Point B, Point C, Point D)** -> checks if points A, B, C, D determine a convex quadrilateral
- **pInTriangle(Point A, Point B, Point C, Point P)** -> checks if point P is inside triangle ABC
- **apartineSegm(Point A, Point B, Point P)** -> checks if point P is on segment [AB]
- **apartineInfConv(Point A, Point B, Point C, Point D, Point P)** -> checks if P is in the convex hull of points A, B, C, D
