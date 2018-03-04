#include "bezier.h"

Vector2 getQuadraticPoint(float t, Vector2 p0, Vector2 p1, Vector2 p2)
{
   float u = 1.0 - t;
   float tt = t * t;
   float uu = u * u;

   Vector2 point = {
       .x = (uu * p0.x) + (2 * u * t * p1.x) + (tt * p2.x),
       .y = (uu * p0.y) + (2 * u * t * p1.y) + (tt * p2.y)
   };

   return point;
}

Vector2 getCubicBezierPoint(float t, Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3)
{
    float u = 1.0 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = u * u * u;
    float ttt = tt * t;

    Vector2 point = {
        .x = (uuu  * p0.x) + (3 * uu * t * p1.x) + (3 * u * tt * p2.x) + (ttt * p3.x),
        .y = (uuu  * p0.y) + (3 * uu * t * p1.y) + (3 * u * tt * p2.y) + (ttt * p3.y)
    };

    return point; 
}
