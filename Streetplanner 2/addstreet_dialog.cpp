#include "addstreet_dialog.h"
#include "ui_addstreet_dialog.h"
#include "city.h"
#include "street.h"
#include "map.h"

#include <QString>
#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QPixmap>

addstreet_dialog::addstreet_dialog(const QList<City*>& cityList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addstreet_dialog)
{
    ui->setupUi(this);

    QPixmap pic("/Users/lmlst/Streetplanner/Bilder/street.png"); // extra Bild
    ui->label_bildstreet->setPixmap(pic.scaled(ui->label_bildstreet->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)); // aus Internet


    // Schleife um ComboBoxen zu befüllen
    for (const auto city : cityList)
    {
        ui->comboBox_add_street1->addItem(city->getName());
        ui->comboBox_add_street2->addItem(city->getName());
    }
}

addstreet_dialog::~addstreet_dialog()
{
    delete ui;
}

 Street* addstreet_dialog::generateStreet(Map* map) const
{
     QString startName = ui->comboBox_add_street1->currentText();
     QString endName = ui->comboBox_add_street2->currentText();

     if (startName.isEmpty() || endName.isEmpty())
         {
             qDebug() << "Fehler. Start- oder Zielstadt wurde nicht ausgewählt.";
             return nullptr;
         }
     // Schleife um zu verhindern, dass mit identischen Städten gearbeitet wird. // Ohne diese Schleife würde das Programm abstürzen
     else if (startName == endName)
     {
         qDebug() << "Fehler: Ausgewählte Städte sind gleich";
         return nullptr;
     }

     City* startCity = map->findCity(startName);
     City* endCity = map->findCity(endName);

     if (!startCity || !endCity) // wenn die Stadt nicht gefunden wurde dann nullptr
     {
         qDebug() << "Fehler: Stadt wurde nicht gefunden.";
         return nullptr;
     }

     return new Street(startCity, endCity); // neue erstellte Strasse zwischen den ausgewählten Städten wird zurückgegeben
}
