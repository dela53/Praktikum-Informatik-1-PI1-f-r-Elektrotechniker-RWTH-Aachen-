#include "city.h"

#include <QString>
#include <QDebug>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QBrush>
#include <QPen>
#include <QGraphicsTextItem>

City::City(QString name, int x, int y)
    : name(name), x(x), y(y) // Initialisierungsliste setzt die Attribute
{}

void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(x, y, 10, 10, QPen(Qt::red), QBrush(Qt::green)); // Fügt ein roten Punkt ein
    qDebug() << "Stadt" << name << "wurde bei den Koordinaten (" << x << "," << y << ") gesetzt";
    QGraphicsTextItem* stadtname = new QGraphicsTextItem; // Label für Stadtname wird erstellt
    stadtname->setPos(x+10, y+5) ; // Position des Textes
    stadtname->setPlainText(name); // Text
    scene.addItem(stadtname); // fügt den Label zur Grafik ein
}

QString City::getName() const
{
    return name;
}

int City::getX() const
{
    return x+5;
}

int City::getY() const
{
    return y+5;
}
