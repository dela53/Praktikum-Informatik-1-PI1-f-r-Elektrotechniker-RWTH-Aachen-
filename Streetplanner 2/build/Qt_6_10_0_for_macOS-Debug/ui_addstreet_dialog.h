/********************************************************************************
** Form generated from reading UI file 'addstreet_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTREET_DIALOG_H
#define UI_ADDSTREET_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_addstreet_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox_add_street1;
    QComboBox *comboBox_add_street2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_bildstreet;
    QLabel *label_4;

    void setupUi(QDialog *addstreet_dialog)
    {
        if (addstreet_dialog->objectName().isEmpty())
            addstreet_dialog->setObjectName("addstreet_dialog");
        addstreet_dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(addstreet_dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        comboBox_add_street1 = new QComboBox(addstreet_dialog);
        comboBox_add_street1->setObjectName("comboBox_add_street1");
        comboBox_add_street1->setGeometry(QRect(10, 100, 103, 32));
        comboBox_add_street2 = new QComboBox(addstreet_dialog);
        comboBox_add_street2->setObjectName("comboBox_add_street2");
        comboBox_add_street2->setGeometry(QRect(10, 160, 103, 32));
        label = new QLabel(addstreet_dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 80, 58, 16));
        label_2 = new QLabel(addstreet_dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 140, 58, 16));
        label_3 = new QLabel(addstreet_dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 191, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(16);
        label_3->setFont(font);
        label_bildstreet = new QLabel(addstreet_dialog);
        label_bildstreet->setObjectName("label_bildstreet");
        label_bildstreet->setGeometry(QRect(190, 40, 201, 181));
        label_4 = new QLabel(addstreet_dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(300, 220, 71, 16));
        QFont font1;
        font1.setPointSize(11);
        label_4->setFont(font1);

        retranslateUi(addstreet_dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addstreet_dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addstreet_dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addstreet_dialog);
    } // setupUi

    void retranslateUi(QDialog *addstreet_dialog)
    {
        addstreet_dialog->setWindowTitle(QCoreApplication::translate("addstreet_dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addstreet_dialog", "Start", nullptr));
        label_2->setText(QCoreApplication::translate("addstreet_dialog", "Ziel", nullptr));
        label_3->setText(QCoreApplication::translate("addstreet_dialog", "Verbinden Sie eine Stadt", nullptr));
        label_bildstreet->setText(QString());
        label_4->setText(QCoreApplication::translate("addstreet_dialog", "AI generated", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addstreet_dialog: public Ui_addstreet_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTREET_DIALOG_H
