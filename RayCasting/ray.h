#ifndef RAY_H
#define RAY_H

//c++
#include <iostream>

//qt
#include <QPainter>
#include <QDebug>

//custom
#include <vector3d.h>

class ray
{
public:
    ray(Vector3D startPos, float angle = 0);
    Vector3D cast(Vector3D &a, Vector3D &b);

    void show(QPainter *painter);

    void update(Vector3D &pos);
private:
    float _angle;
    float _distance;
    Vector3D _a;
    Vector3D _start_pos;
};

#endif // RAY_H
