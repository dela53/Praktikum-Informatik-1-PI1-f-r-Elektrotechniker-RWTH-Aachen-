#include "map.h"
#include "city.h"
#include "street.h"

#include <QList>
#include <QDebug>
#include <QVector>
#include <cmath>

Map::Map() {}

void Map::addCity(City* city)
{
    cityList.append(city); // Stadt wird in der Liste gespeichert
    qDebug() << "Neue Stadt hinzugefügt:" << city->getName();
}

bool Map::addStreet(Street* street)
{
    if (cityList.contains(street->getStartCity()) && cityList.contains(street->getEndCity())) // Wenn sich zwei Städte in der Liste befineden, dann true
    {
    streetList.append(street); // Straße wird zur Liste hinzugefügt
    qDebug() << "Strasse wurde erfolgreich hinzugefügt";
    return true;

    }
    else
    {
        qDebug() << "Fehler: Es fehlt mind. eine Stadt in der Karte";
        return false;
    }

}

void Map::draw(QGraphicsScene& scene) const // Referenz auf Scene und keine Kopie
{
    for (const auto city : cityList)
    {
        city->draw(scene);
    }

    for (const auto street : streetList)
    {
        street->draw(scene);
    }
}

 City* Map::findCity(const QString cityName) const
{
     for (const auto city : cityList)
    {
        if (city->getName() == cityName)
         {
             qDebug() << "Stadt gefunden";
             return city;
         }
     }
     return nullptr; // kein else weil es unnötig ist
}

 QVector<Street*> Map::getStreetList(const City* city) const
{
    QList<Street*> resultStreetList; // neue dynamische Liste
    for (const auto street : streetList)
    {
        if (street->getStartCity() == city || street->getEndCity() == city)
        {
            resultStreetList.append(street); // Gefundene Straße wird zur neulich erstellte Liste hinzugefügt
        }
    }
    return resultStreetList; // Liste wird zurückgegeben
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getStartCity() == city) return street->getEndCity();
    else if (street->getEndCity() == city) return street->getStartCity();
    else return nullptr;
}

double Map::getLength(const Street* street) const
{
    int x1 = street->getStartCity()->getX();
    int y1 = street->getStartCity()->getY();
    int x2 = street->getEndCity()->getX();
    int y2 = street->getEndCity()->getY();

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // Formel zur Berechnung der Länge der Linie // für sqrt und pow cmath includieren
}

const QList<City*>& Map::getCityList() const
{
    return cityList;
}
