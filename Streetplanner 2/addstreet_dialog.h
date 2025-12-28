#ifndef ADDSTREET_DIALOG_H
#define ADDSTREET_DIALOG_H

#include <QDialog>
#include "street.h"
#include "map.h"

namespace Ui {
class addstreet_dialog;
}

class addstreet_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit addstreet_dialog(const QList<City*>& cityList, QWidget *parent = nullptr);
    ~addstreet_dialog();

    /**
     * @brief Generiert eine Straße, welche zwei ausgewählte Städte verbindet
     * @param pointer auf Map
     * @return street
     */
    Street* generateStreet(Map* map) const;

private:
    Ui::addstreet_dialog *ui;
};

#endif // ADDSTREET_DIALOG_H
