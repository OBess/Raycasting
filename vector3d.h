#ifndef VECTOR3D_H
#define VECTOR3D_H

//c++
#include <iostream>
#include <cmath>

class Vector3D
{
public:
    Vector3D(float x, float y, float z = 0);
    Vector3D(const Vector3D &vector);
    Vector3D();

    float x();
    float y();
    float z();

    Vector3D& vector(float x, float y, float z = 0);
    Vector3D& vector(Vector3D &vector);
    Vector3D& vector(Vector3D vector);
    Vector3D& x(float x);
    Vector3D& y(float y);
    Vector3D& z(float z);
    Vector3D& incrX(float x = 0);
    Vector3D& incrY(float y = 0);
    Vector3D& incrZ(float z = 0);
    Vector3D& decrX(float x = 0);
    Vector3D& decrY(float y = 0);
    Vector3D& decrZ(float z = 0);

    float len();
    Vector3D copy();

    Vector3D& rotateAngle2D(float angle, Vector3D point);
    Vector3D& rotateAngle2D(float angle);

    float scalar(const Vector3D vector);
    Vector3D& add(const Vector3D vector);
    Vector3D& sub(const Vector3D vector);
    Vector3D& div(float number);
    Vector3D& mult(float number);
    Vector3D& normalize();
    Vector3D prod(const Vector3D vector);

    static Vector3D one();
    static Vector3D zero();
    static Vector3D neg();

    friend std::ostream& operator<<(std::ostream &os, const Vector3D &vector);
    bool operator==(const Vector3D &vector);
    Vector3D& operator=(const Vector3D &vector);
private:
    float _x, _y, _z;
};

#endif // VECTOR3D_H
