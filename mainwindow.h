#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>
#include <panel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_actionChange_Colors_triggered();
    void on_actionChange_count_boundaries_triggered();
    void on_actionChange_added_angle_triggered();
    void on_actionChange_boundary_color_triggered();

    void on_actionChange_mode_triggered();

    void on_actionReset_triggered();

private:
    Ui::MainWindow *ui;
    Panel* _panel;
};
#endif // MAINWINDOW_H
