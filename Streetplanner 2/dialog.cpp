#include "dialog.h"
#include "ui_dialog.h"
#include "city.h"

#include <QString>
#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QPixmap>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPixmap pic("/Users/lmlst/Streetplanner/Bilder/city.png"); // extra Bild
    ui->label_image->setPixmap(pic.scaled(ui->label_image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)); // aus Internet

}

Dialog::~Dialog()
{
    delete ui;
}

City* Dialog::generateCity()
{
    bool x_exists, y_exists;
    QString inputCityName = ui->lineEdit_city_name->text();
    int x = ui->lineEdit_x->text().toInt(&x_exists);
    int y = ui->lineEdit_y->text().toInt(&y_exists);

    if (inputCityName.isEmpty() || !x_exists || !y_exists) // Zeiger auf Null wird zurückgegeben wenn die Eingabe ungültig ist.
    {
        qDebug() << "Ungültige Eingabe.";
        QMessageBox::warning(this, "Ungültige Eingabe.", "Bitte geben Sie gültige Parameter ein."); // Gibt eine Warnung in einem extra Fenster aus
        return nullptr; // gibt kein Objekt zurück
    }
    else // sonst wird die erzeugte Stadt zurückgegeben
    {
        City* generatedCity = new City(inputCityName, x, y);
        return generatedCity;
    }
}


