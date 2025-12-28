#ifndef DIALOG_H
#define DIALOG_H

#include "city.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    /**
     * @brief Diese Funktion generiert eine Stadt
     * @return pointer auf City
     */
    City* generateCity();


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
