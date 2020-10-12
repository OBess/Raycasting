#include "ray.h"

//Main
ray::ray(Vector3D startPos, float angle) : _angle(angle), _distance(50), _start_pos(startPos)
{
    _a = Vector3D(1, 0);
    _a.rotateAngle2D(angle);
}
//~Main


//Drawing
void ray::show(QPainter *p){
    p->drawLine(_start_pos.x(), _start_pos.y(), _start_pos.x() + _a.x() * _distance, _start_pos.y() + _a.y() * _distance);
}
//~Drawing


//Operations
Vector3D ray::cast(Vector3D &a, Vector3D &b){
    Vector3D res = _start_pos;

    float x3 = _start_pos.x();
    float y3 = _start_pos.y();
    float x4 = _start_pos.x() + _a.x();
    float y4 = _start_pos.y() + _a.y();
    float x1 = a.x();
    float y1 = a.y();
    float x2 = b.x();
    float y2 = b.y();

    float par = (x1 - x2)*(y3 - y4)-(y1 - y2)*(x3 - x4);
    if(par == 0)
        return res;

    float t = ((x1-x3)*(y3-y4)-(y1-y3)*(x3-x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
    float u = -((x1-x2)*(y1-y3)-(y1-y2)*(x1-x3))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));


    if(t < 1 && t > 0 && u >= 0){
       float x = x1 + t * (x2 - x1);
       float y = y1 + t * (y2 - y1);
       res = Vector3D(x, y);
    }

    return res;
}
void ray::update(Vector3D &pos){
    _start_pos = pos;
}
//~Operations
