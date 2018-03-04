#ifndef bezier_h
#define bezier_h

#define BEZIER_QUADRATIC 1
#define BEZIER_CUBIC 2
#define SEGMENT_COUNT 1000

typedef struct Vector2 {
    float x;
    float y;
} Vector2;

Vector2 getQuadraticPoint(float t, Vector2 p0, Vector2 p1, Vector2 p2);
Vector2 getCubicBezierPoint(float t, Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3);
#endif
