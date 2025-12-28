#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>
#include <QDebug>

class City
{
public:
    City(QString name, int x, int y); // Konstruktor: Name und Koordinaten der Stadt setzen

     //virtual ~City();

    /**
     * @brief Diese Funktion zeichnet die Stadt in der Karte ein
     * @return null
     */
    virtual void draw(QGraphicsScene& scene); // virtuell damit sie überschrieben wird

    /**
     * @brief Diese Funktion gibt den Namen einer Stadt aus
     * @return QString
     */
    QString getName() const;

    /**
     * @brief Diese Funktion gibt die x-Koordinaten einer Stadt aus
     * @return integer
     */
    int getX() const;

    /**
     * @brief Diese Funktion gibt die y-Koordinaten einer Stadt aus
     * @return integer
     */
    int getY() const;

private:
    QString name; // Name der Stadt
    int x; // x-Koordinate
    int y; // y-Koordinate
};

#endif // CITY_H
