#ifndef BOUNDARY_H
#define BOUNDARY_H

//qt
#include <QPainter>

//custom
#include <vector3d.h>

class boundary
{
public:
    boundary(float x1, float y1, float x2, float y2);

    Vector3D& a();
    Vector3D& b();
    Vector3D& vector();

    void a(Vector3D vectorA);
    void b(Vector3D vectorB);

    void show(QPainter *painter);
private:
    Vector3D _a, _b;
};

#endif // BOUNDARY_H
