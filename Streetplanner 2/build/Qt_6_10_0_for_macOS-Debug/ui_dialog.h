/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_city_name;
    QLineEdit *lineEdit_x;
    QLineEdit *lineEdit_y;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_image;
    QLabel *label_image_source;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        lineEdit_city_name = new QLineEdit(Dialog);
        lineEdit_city_name->setObjectName("lineEdit_city_name");
        lineEdit_city_name->setGeometry(QRect(10, 80, 161, 31));
        lineEdit_city_name->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_x = new QLineEdit(Dialog);
        lineEdit_x->setObjectName("lineEdit_x");
        lineEdit_x->setGeometry(QRect(10, 150, 61, 31));
        lineEdit_x->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_y = new QLineEdit(Dialog);
        lineEdit_y->setObjectName("lineEdit_y");
        lineEdit_y->setGeometry(QRect(70, 150, 61, 31));
        lineEdit_y->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 130, 101, 16));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 91, 16));
        label_image = new QLabel(Dialog);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(200, 30, 201, 191));
        label_image_source = new QLabel(Dialog);
        label_image_source->setObjectName("label_image_source");
        label_image_source->setGeometry(QRect(330, 220, 61, 16));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        label_image_source->setFont(font);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 191, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setKerning(false);
        label_3->setFont(font1);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lineEdit_city_name->setInputMask(QString());
        lineEdit_city_name->setPlaceholderText(QCoreApplication::translate("Dialog", "Name eingeben", nullptr));
        lineEdit_x->setPlaceholderText(QCoreApplication::translate("Dialog", "X", nullptr));
        lineEdit_y->setPlaceholderText(QCoreApplication::translate("Dialog", "Y", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Koordinaten:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Stadt:", nullptr));
        label_image->setText(QString());
        label_image_source->setText(QCoreApplication::translate("Dialog", "AI generated", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "F\303\274gen Sie eine Stadt hinzu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
