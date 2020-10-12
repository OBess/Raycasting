#include "vector3d.h"

//Main
Vector3D::Vector3D(float x, float y, float z) : _x{x}, _y{y}, _z{z}{}
Vector3D::Vector3D(const Vector3D &v) : _x{v._x}, _y{v._y}, _z{v._z}{}
Vector3D::Vector3D() : _x{0}, _y{0}, _z{0}{}
//~Main


//Getters
float Vector3D::x(){
    return _x;
}
float Vector3D::y(){
    return _y;
}
float Vector3D::z(){
    return _z;
}
//~Getters


//Setters
Vector3D& Vector3D::vector(float x, float y, float z){
    this->_x = x;
    this->_y = y;
    this->_z = z;
    return *this;
}
Vector3D& Vector3D::vector(Vector3D &v){
    *this = v;
    return *this;
}
Vector3D& Vector3D::vector(Vector3D v){
    *this = v;
    return *this;
}
Vector3D& Vector3D::x(float n){
    _x = n;
    return *this;
}
Vector3D& Vector3D::y(float n){
    _y = n;
    return *this;
}
Vector3D& Vector3D::z(float n){
    _z = n;
    return *this;
}
Vector3D& Vector3D::incrX(float x){
    _x += x;
    return *this;
}
Vector3D& Vector3D::incrY(float y){
    _y += y;
    return *this;
}
Vector3D& Vector3D::incrZ(float z){
    _z += z;
    return *this;
}
Vector3D& Vector3D::decrX(float x){
    _x -= x;
    return *this;
}
Vector3D& Vector3D::decrY(float y){
    _y -= y;
    return *this;
}
Vector3D& Vector3D::decrZ(float z){
    _z -= z;
    return *this;
}
//~Setters


//Informations
float Vector3D::len(){
    return std::sqrt(_x * _x + _y * _y + _z * _z);
}
Vector3D Vector3D::copy(){
    return *this;
}
//~Informations


//Basic opetarions
float Vector3D::scalar(const Vector3D v){
    return _x * v._x + _y * v._y + _z * v._z;
}
Vector3D& Vector3D::add(const Vector3D v){
    _x += v._x;
    _y += v._y;
    _z += v._z;
    return *this;
}
Vector3D& Vector3D::sub(const Vector3D v){
    _x -= v._x;
    _y -= v._y;
    _z -= v._z;
    return *this;
}
Vector3D& Vector3D::div(float n){
    _x /= n;
    _y /= n;
    _z /= n;
    return *this;
}
Vector3D& Vector3D::mult(float n){
    _x *= n;
    _y *= n;
    _z *= n;
    return *this;
}
Vector3D Vector3D::prod(const Vector3D v){
    float pX = _y * v._z - _z * v._y;
    float pY = _x * v._z - _z * v._x;
    float pZ = _x * v._y - _y * v._x;
    return Vector3D(pX, pY, pZ);
}
Vector3D& Vector3D::normalize(){
    float length = len();
    _x /= length;
    _y /= length;
    _z /= length;
    return *this;
}
//~Basic opetarions


//Operations on vectors
Vector3D& Vector3D::rotateAngle2D(float angle, Vector3D point){
    return sub(point).rotateAngle2D(angle).add(point);
}
Vector3D& Vector3D::rotateAngle2D(float angle){
    float localX = _x,
          localY = _y;
    _x = localX * std::cos(angle) - localY * std::sin(angle);
    _y = localX * std::sin(angle) + localY * std::cos(angle);
    return *this;
}
//~Operations on vectors


//Staitcs
Vector3D Vector3D::one(){
    return Vector3D(1, 1, 1);
}
Vector3D Vector3D::zero(){
    return Vector3D();
}
Vector3D Vector3D::neg(){
    return Vector3D(-1, -1, -1);
}
//~Statics


//Operators
std::ostream& operator<<(std::ostream &os, const Vector3D &v)
{
    os << "x: " << v._x << "\ny: " << v._y << "\nz: " << v._z << "\n";
    return os;
}
bool Vector3D::operator==(const Vector3D &vector){
    if(_x == vector._x && _y == vector._y && _z == vector._z)
        return true;
    return false;
}
Vector3D& Vector3D::operator=(const Vector3D &v){
    this->_x = v._x;
    this->_y = v._y;
    this->_z = v._z;
    return *this;
}
//~Operators
