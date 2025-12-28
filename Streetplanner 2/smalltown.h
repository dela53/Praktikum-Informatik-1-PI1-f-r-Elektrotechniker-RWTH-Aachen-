#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include "city.h"

#include <QString>
#include <QGraphicsScene>


class SmallTown : public City
{
public:
    SmallTown(QString name, int x, int y);
    void draw(QGraphicsScene &scene);
};

#endif // SMALLTOWN_H
