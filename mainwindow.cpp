#include "mainwindow.h"
#include "ui_mainwindow.h"

//Main
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->_panel = new Panel(this);
}

MainWindow::~MainWindow()
{
    delete this->_panel;
    delete this->ui;
}
//~Main


//Events
void MainWindow::keyPressEvent(QKeyEvent *event){
    this->_panel->keyPressEvent(event);
}
void MainWindow::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    this->_panel->rasizeWindow();
}
//~Events


//Slots
void MainWindow::on_actionChange_Colors_triggered()
{
    this->_panel->changeRayColor();
}
void MainWindow::on_actionChange_count_boundaries_triggered()
{
    this->_panel->changeCountBoundaries();
}
void MainWindow::on_actionChange_added_angle_triggered()
{
    this->_panel->changeAddingAngle();
}
void MainWindow::on_actionChange_boundary_color_triggered()
{
    this->_panel->changeBoundaryColor();
}
//~Slots


