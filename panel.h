#ifndef PANEL_H
#define PANEL_H

//c++
#include <iostream>
#include <vector>
#include <ctime>
#include <limits>
#include <thread>

//qt
#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QKeyEvent>
#include <QInputDialog>
#include <QColorDialog>
#include <QDir>
#include <QTimer>

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
    ~Panel();

    void keyPressEvent(QKeyEvent *event) override;
    void changeRayColor();
    void changeBoundaryColor();
    void changeAddingAngle();
    void changeCountBoundaries();
    void rasizeWindow();
    void changeMode();
    void reset();

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
    Vector3D _mouse_pos;

    QWidget *parent;

    QColor _color_rays;
    QColor _color_boundaries;
    QTimer *_timer;
    int _count_boundaries;
    float _angle;
    float _circle_size;
    bool _mode;
    bool _move;
};

#endif // PANEL_H
