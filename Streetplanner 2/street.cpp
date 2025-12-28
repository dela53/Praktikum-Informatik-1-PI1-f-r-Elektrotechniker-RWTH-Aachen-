#include "street.h"
#include "city.h"
//#include "map.h"

#include <QString>
#include <QDebug>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QBrush>
#include <QPen>
#include <QGraphicsTextItem>

Street::Street(City* start, City* ende)
       :startCity(start), endCity(ende)
{}

City* Street::getStartCity() const
{
    return startCity;
}

City* Street::getEndCity() const
{
    return endCity;
}

void Street::draw(QGraphicsScene& scene)
{
    scene.addLine(startCity->getX(), startCity->getY(), endCity->getX(), endCity->getY(), QPen(Qt::blue)); // Fügt eine blaue Linie ein
    qDebug() << "Strasse wurde zwischen" << startCity->getName() << "und" << endCity->getName() << "gesetzt";
}

void Street::drawRed(QGraphicsScene& scene) const
{
    scene.addLine(startCity->getX(), startCity->getY(), endCity->getX(), endCity->getY(), QPen(Qt::red)); // Fügt eine blaue Linie ein
    qDebug() << "Schnellste Strasse wurde zwischen" << startCity->getName() << "und" << endCity->getName() << "gesetzt";
}
