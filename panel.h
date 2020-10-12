#ifndef PANEL_H
#define PANEL_H

//c++
#include <iostream>
#include <vector>
#include <ctime>
#include <limits>

//qt
#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QKeyEvent>
#include <QInputDialog>
#include <QColorDialog>
#include <QDir>

//custom
#include <vector3d.h>
#include <RayCasting/boundary.h>
#include <RayCasting/ray.h>

//
#define INF 10000

class Panel : public QWidget
{
    Q_OBJECT
public:
    explicit Panel(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override;
    void changeRayColor();
    void changeBoundaryColor();
    void changeAddingAngle();
    void changeCountBoundaries();
    void rasizeWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void _init();
    void updateCircle();

    std::vector<boundary> boundraies;
    std::vector<ray> rays;
    std::vector<Vector3D> dots;

    Vector3D _circle;
    QWidget *parent;

    QColor _color_rays;
    QColor _color_boundaries;
    int _count_boundaries;
    float _angle;
    float _circle_size;
    bool _move;
};

#endif // PANEL_H
