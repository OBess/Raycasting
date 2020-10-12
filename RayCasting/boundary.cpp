#include "boundary.h"
//Main
boundary::boundary(float x1, float y1, float x2, float y2) : _a(Vector3D(x1, y1)), _b(Vector3D(x2, y2)){}
//~Main


//Getters
Vector3D& boundary::a(){
    return _a;
}
Vector3D& boundary::b(){
    return _b;
}
Vector3D& boundary::vector(){
    return _a;
}
//~Getters


//Setters
void boundary::a(Vector3D v){
    _a = v;
}
void boundary::b(Vector3D v){
    _b = v;
}
//~Setters


//Drawing
void boundary::show(QPainter *p){
    p->drawLine(_a.x(), _a.y(), _b.x(), _b.y());
}
//~Drawing
