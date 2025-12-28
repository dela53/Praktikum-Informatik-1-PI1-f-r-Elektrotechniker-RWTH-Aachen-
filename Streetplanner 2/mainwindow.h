#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "mapio.h"

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_test_draw_city_clicked();

    void on_pushButton_test_add_Street_clicked();

    void on_checkBox_hide_test_clicked();

    void on_pushButton_add_city_clicked();

    void on_pushButton_fill_map_clicked();

    void on_pushButton_test_abstract_map_clicked();

    void on_pushButton_test_dijkstra_clicked();

    void on_pushButton_find_fastest_way_clicked();

    void on_pushButton_add_street_clicked();

    void on_actionOpen_city_file_triggered();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene; // Attribut von der Klasse QGraphicsScene
    Map* map;
    MapIo* fill;
};
#endif // MAINWINDOW_H
