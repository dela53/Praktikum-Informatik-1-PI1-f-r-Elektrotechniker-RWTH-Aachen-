#ifndef STREET_H
#define STREET_H

#include "city.h"

#include <QGraphicsTextItem>
#include <QString>
#include <QGraphicsScene>
#include <QDebug>


class Street
{
public:
    Street(City* start, City* ende);

    /**
     * @brief Zeichnet eine Straße in der Karte ein
     * @param QGraphicsScene& scene
     * @return null
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Zeichnet eine rote Straße in der Karte ein, welche die schnellste Route simbolisiert
     * @param QGraphicsScene& scene
     * @return null
     */
    void drawRed(QGraphicsScene& scene) const;

    /**
     * @brief Gibt den Start der Straße aus
     * @return pointer auf City
     */
    City* getStartCity() const;

    /**
     * @brief Gibt das Ziel bzw. das Ende der Straße aus
     * @return pointer auf City
     */
    City* getEndCity() const;

private:
    City* startCity;
    City* endCity;
};

#endif // STREET_H
