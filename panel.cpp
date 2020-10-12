#include "panel.h"

//Main
Panel::Panel(QWidget *p) : QWidget(p)
{
    setMouseTracking(true);
    this->setGeometry(p->geometry());
    parent = p;
    p = NULL;

    _color_rays = "#FFFFFF";
    _color_boundaries = "#FFFFFF";
    _count_boundaries = 5;
    _angle = 1;

    _init();
}
//~Main


//Init
void Panel::_init(){
    rays.clear();
    boundraies.clear();

    float startX = width() / 2;
    float startY = height() / 2;

    _circle = Vector3D(startX, startY);
    _circle_size = 0;

    for(float angle = 0; angle <= 360; angle += _angle)
        rays.push_back(ray(Vector3D(startX, startY), angle));

    float x1, x2, y1, y2;

    std::srand(std::time(NULL));

    for(int i = 0; i < _count_boundaries; i++)
    {
        x1 = std::rand() % width();
        x2 = std::rand() % width();
        y1 = std::rand() % height();
        y2 = std::rand() % height();
        boundraies.push_back(boundary(x1, y1, x2, y2));
    }

    boundraies.push_back(boundary(-1, -1, width() + 1, -1));
    boundraies.push_back(boundary(-1, -1, -1, height() + 1));
    boundraies.push_back(boundary(-1, height() + 1, width() + 1, height() + 1));
    boundraies.push_back(boundary(width() + 1, -1, width() + 1, height() + 1));

    update();

    updateCircle();
}
//~Init


//Events
void Panel::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter p(this);

    p.setBrush(Qt::black);
    p.drawRect(-1, -1, width() + 1, height() + 1);

    p.setPen(_color_boundaries);
    for(size_t i = 0; i < boundraies.size(); i++)
        boundraies.at(i).show(&p);

    p.setPen(_color_rays);
    p.drawEllipse(_circle.x() - _circle_size / 2, _circle.y() - _circle_size / 2, _circle_size, _circle_size);
    for(size_t i = 0; i < dots.size(); i++)
        p.drawLine(_circle.x(), _circle.y(), dots.at(i).x(), dots.at(i).y());
}
void Panel::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
    {
        _circle.decrY(4);
        updateCircle();
    }
    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
    {
        _circle.incrX(4);
        updateCircle();
    }
    if(event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
    {
        _circle.incrY(4);
        updateCircle();
    }
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
    {
        _circle.decrX(4);
        updateCircle();
    }
    if(event->key() == Qt::Key_R){
        _init();
    }
}
void Panel::mouseMoveEvent(QMouseEvent *event){
    if(_move){
        _circle.vector(Vector3D(event->x(), event->y()));
        updateCircle();
    }
}
void Panel::mousePressEvent(QMouseEvent *event){
    Q_UNUSED(event);
    _move = true;
}
void Panel::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    _move = false;
}
//~Events


//User settings
void Panel::changeRayColor(){
    QColor color = QColorDialog::getColor(_color_rays, this, "Change ray color");
    _color_rays = color;
    update();
}
void Panel::changeBoundaryColor(){
    QColor color = QColorDialog::getColor(_color_boundaries, this, "Change boundary color");
    _color_boundaries = color;
    update();
}
void Panel::changeAddingAngle(){
    bool ok;
    float angle = QInputDialog::getDouble(this, tr("Change adding angle"), tr("Angle"), _angle, 0.00001f, 360, 10000, &ok);
    if(ok){
        _angle = angle;
        _init();
    }
}
void Panel::changeCountBoundaries(){
    bool ok;
    float count_boundaries = QInputDialog::getDouble(this, tr("Change count boundaries"), tr("Count"), _count_boundaries, 0, INF, 1, &ok);
    if(ok){
        _count_boundaries = count_boundaries;
        _init();
    }
}
void Panel::rasizeWindow(){
    this->setGeometry(x(), y(), parent->width(), parent->height());
    _init();
}
//~User settings


void Panel::updateCircle(){
    for(size_t i = 0; i < rays.size(); i++)
        rays.at(i).update(_circle);

    dots.clear();
    Vector3D added;

    for(size_t i = 0; i < rays.size(); i++){
        added = Vector3D(INF, INF);
        for(size_t j = 0; j < boundraies.size(); j++){
            Vector3D casted = rays.at(i).cast(boundraies.at(j).a(), boundraies.at(j).b());
            if(casted == _circle)
                continue;

            float lenCasted = _circle.copy().sub(casted).len();
            float lenAdded = _circle.copy().sub(added).len();
            if(lenCasted < lenAdded)
                added = casted;
        }
        dots.push_back(added);
    }
    update();
}
