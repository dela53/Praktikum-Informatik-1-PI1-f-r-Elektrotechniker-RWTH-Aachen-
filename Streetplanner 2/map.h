#ifndef MAP_H
#define MAP_H

#include "abstractmap.h"
#include "city.h"
#include "street.h"

#include <QDebug>
#include <QList>

class Map : public AbstractMap // geerbt von AbstractMap
{
public:
    Map();

    /**
     * @brief Fügt eine Stadt in der Karte hinzu
     * @param City* city
     * @return null
     */
    void addCity(City* city);

    /**
     * @brief Verbindet zwei Städte mit einer Straße
     * @param Street* street
     * @return bool
     */
    bool addStreet(Street* street);

    /**
     * @brief Zeichnet eine Stadt in der Karte ein
     * @param QGraphicsScene& scene
     * @return void
     */
    void draw(QGraphicsScene& scene) const;

    /**
     * @brief Findet eine Stadt in der Liste durch den Namen
     * @param const QString cityName
     * @return pointer auf city
     */
    City* findCity(const QString cityName) const;

    /**
     * @brief Diese Funktion gibt die liste der Straßen aus
     * @param const City* city
     * @return pointer auf Container QVector
     */
    QVector<Street*> getStreetList(const City* city) const;

    /**
     * @brief Diese Funktion gibt die Liste der Stadt aus
     * @return pointer auf City Liste
     */
    const QList<City*>& getCityList() const;

    /**
     * @brief Gibt die Stadt aus die mit der eingegebenen Stadt verbunden ist aus
     * @param Street* street
     * @param City* city
     * @return pointer auf City
     */
    City* getOppositeCity(const Street* street, const City* city) const;

    /**
     * @brief Gibt die Länge einer ausgewählten Straße aus
     * @param Street* street
     * @return double
     */
    double getLength(const Street* street) const;

private:
    QList<City*> cityList;
    QList<Street*> streetList;
};

#endif // MAP_H
