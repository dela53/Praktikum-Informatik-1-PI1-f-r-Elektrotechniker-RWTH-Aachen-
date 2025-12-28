/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionsdf;
    QAction *actionsdf_2;
    QAction *actionsdf_3;
    QAction *actionsdf_4;
    QAction *actionsdf_5;
    QAction *actionSave;
    QAction *actionTrenner_hinzuf_gen;
    QAction *actionExit;
    QAction *actionClear_Scene;
    QAction *actionAbout;
    QAction *actionOpen_city_file;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_teste_was;
    QLabel *File;
    QLineEdit *lineEdit_teste_was;
    QPushButton *pushButton_test_draw_city;
    QPushButton *pushButton_test_add_Street;
    QCheckBox *checkBox_hide_test;
    QPushButton *pushButton_add_city;
    QPushButton *pushButton_fill_map;
    QPushButton *pushButton_test_abstract_map;
    QPushButton *pushButton_test_dijkstra;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_find_fastest_way;
    QComboBox *comboBox_end_city;
    QComboBox *comboBox_start_city;
    QPushButton *pushButton_add_street;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuScene;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1111, 776);
        actionsdf = new QAction(MainWindow);
        actionsdf->setObjectName("actionsdf");
        actionsdf_2 = new QAction(MainWindow);
        actionsdf_2->setObjectName("actionsdf_2");
        actionsdf_3 = new QAction(MainWindow);
        actionsdf_3->setObjectName("actionsdf_3");
        actionsdf_4 = new QAction(MainWindow);
        actionsdf_4->setObjectName("actionsdf_4");
        actionsdf_5 = new QAction(MainWindow);
        actionsdf_5->setObjectName("actionsdf_5");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setCheckable(false);
        actionSave->setChecked(false);
        actionSave->setEnabled(false);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        actionSave->setIcon(icon);
        actionSave->setIconVisibleInMenu(true);
        actionSave->setShortcutVisibleInContextMenu(true);
        actionTrenner_hinzuf_gen = new QAction(MainWindow);
        actionTrenner_hinzuf_gen->setObjectName("actionTrenner_hinzuf_gen");
        actionTrenner_hinzuf_gen->setEnabled(false);
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        actionTrenner_hinzuf_gen->setIcon(icon1);
        actionTrenner_hinzuf_gen->setIconVisibleInMenu(true);
        actionTrenner_hinzuf_gen->setShortcutVisibleInContextMenu(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setEnabled(true);
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionExit->setIcon(icon2);
        actionExit->setIconVisibleInMenu(true);
        actionExit->setShortcutVisibleInContextMenu(true);
        actionClear_Scene = new QAction(MainWindow);
        actionClear_Scene->setObjectName("actionClear_Scene");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        actionClear_Scene->setIcon(icon3);
        actionClear_Scene->setIconVisibleInMenu(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::DialogInformation));
        actionAbout->setIcon(icon4);
        actionAbout->setIconVisibleInMenu(true);
        actionAbout->setShortcutVisibleInContextMenu(false);
        actionOpen_city_file = new QAction(MainWindow);
        actionOpen_city_file->setObjectName("actionOpen_city_file");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionOpen_city_file->setIcon(icon5);
        actionOpen_city_file->setIconVisibleInMenu(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(296, -5, 801, 721));
        graphicsView->setSizeIncrement(QSize(0, 0));
        graphicsView->setBaseSize(QSize(0, 0));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::CrossCursor)));
        graphicsView->setMouseTracking(true);
        graphicsView->setTabletTracking(true);
        graphicsView->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        graphicsView->setAutoFillBackground(false);
        graphicsView->setLineWidth(1);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setDragMode(QGraphicsView::DragMode::RubberBandDrag);
        pushButton_teste_was = new QPushButton(centralwidget);
        pushButton_teste_was->setObjectName("pushButton_teste_was");
        pushButton_teste_was->setGeometry(QRect(10, 70, 271, 32));
        pushButton_teste_was->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        File = new QLabel(centralwidget);
        File->setObjectName("File");
        File->setEnabled(true);
        File->setGeometry(QRect(60, 0, 181, 33));
        File->setMinimumSize(QSize(5, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("SignPainter")});
        font.setPointSize(36);
        font.setBold(true);
        font.setItalic(true);
        File->setFont(font);
        File->setAutoFillBackground(false);
        File->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_teste_was = new QLineEdit(centralwidget);
        lineEdit_teste_was->setObjectName("lineEdit_teste_was");
        lineEdit_teste_was->setGeometry(QRect(10, 40, 271, 21));
        lineEdit_teste_was->setMinimumSize(QSize(0, 0));
        lineEdit_teste_was->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_teste_was->setClearButtonEnabled(true);
        pushButton_test_draw_city = new QPushButton(centralwidget);
        pushButton_test_draw_city->setObjectName("pushButton_test_draw_city");
        pushButton_test_draw_city->setGeometry(QRect(120, 100, 161, 32));
        pushButton_test_draw_city->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        pushButton_test_add_Street = new QPushButton(centralwidget);
        pushButton_test_add_Street->setObjectName("pushButton_test_add_Street");
        pushButton_test_add_Street->setGeometry(QRect(120, 130, 161, 32));
        pushButton_test_add_Street->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        checkBox_hide_test = new QCheckBox(centralwidget);
        checkBox_hide_test->setObjectName("checkBox_hide_test");
        checkBox_hide_test->setGeometry(QRect(10, 100, 111, 31));
        pushButton_add_city = new QPushButton(centralwidget);
        pushButton_add_city->setObjectName("pushButton_add_city");
        pushButton_add_city->setGeometry(QRect(10, 131, 100, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setItalic(true);
        pushButton_add_city->setFont(font1);
        pushButton_add_city->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        pushButton_add_city->setIcon(icon6);
        pushButton_fill_map = new QPushButton(centralwidget);
        pushButton_fill_map->setObjectName("pushButton_fill_map");
        pushButton_fill_map->setGeometry(QRect(10, 160, 101, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setItalic(true);
        pushButton_fill_map->setFont(font2);
        pushButton_fill_map->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        pushButton_fill_map->setIcon(icon6);
        pushButton_test_abstract_map = new QPushButton(centralwidget);
        pushButton_test_abstract_map->setObjectName("pushButton_test_abstract_map");
        pushButton_test_abstract_map->setGeometry(QRect(120, 160, 161, 32));
        pushButton_test_abstract_map->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        pushButton_test_dijkstra = new QPushButton(centralwidget);
        pushButton_test_dijkstra->setObjectName("pushButton_test_dijkstra");
        pushButton_test_dijkstra->setGeometry(QRect(120, 190, 161, 32));
        pushButton_test_dijkstra->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 230, 111, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 230, 91, 16));
        pushButton_find_fastest_way = new QPushButton(centralwidget);
        pushButton_find_fastest_way->setObjectName("pushButton_find_fastest_way");
        pushButton_find_fastest_way->setGeometry(QRect(10, 290, 261, 41));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        pushButton_find_fastest_way->setIcon(icon7);
        comboBox_end_city = new QComboBox(centralwidget);
        comboBox_end_city->setObjectName("comboBox_end_city");
        comboBox_end_city->setGeometry(QRect(140, 250, 131, 32));
        comboBox_start_city = new QComboBox(centralwidget);
        comboBox_start_city->setObjectName("comboBox_start_city");
        comboBox_start_city->setGeometry(QRect(10, 250, 131, 32));
        pushButton_add_street = new QPushButton(centralwidget);
        pushButton_add_street->setObjectName("pushButton_add_street");
        pushButton_add_street->setGeometry(QRect(10, 190, 101, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(12);
        font3.setItalic(false);
        pushButton_add_street->setFont(font3);
        pushButton_add_street->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        pushButton_add_street->setIcon(icon6);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1111, 38));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuFile->setToolTipsVisible(true);
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName("menuScene");
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuScene->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuFile->addAction(actionOpen_city_file);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionTrenner_hinzuf_gen);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuScene->addAction(actionClear_Scene);
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionsdf->setText(QCoreApplication::translate("MainWindow", "sdf", nullptr));
        actionsdf_2->setText(QCoreApplication::translate("MainWindow", "sdf", nullptr));
        actionsdf_3->setText(QCoreApplication::translate("MainWindow", "sdf", nullptr));
        actionsdf_4->setText(QCoreApplication::translate("MainWindow", "sdf", nullptr));
        actionsdf_5->setText(QCoreApplication::translate("MainWindow", "sdf", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionTrenner_hinzuf_gen->setText(QCoreApplication::translate("MainWindow", "Trenner hinzuf\303\274gen", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Meta+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear_Scene->setText(QCoreApplication::translate("MainWindow", "Clear Scene", nullptr));
#if QT_CONFIG(shortcut)
        actionClear_Scene->setShortcut(QCoreApplication::translate("MainWindow", "Meta+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionOpen_city_file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_teste_was->setToolTip(QCoreApplication::translate("MainWindow", "moin", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_teste_was->setText(QCoreApplication::translate("MainWindow", "Test something", nullptr));
        File->setText(QCoreApplication::translate("MainWindow", "Streetplaner\302\256", nullptr));
        lineEdit_teste_was->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ihre Eingabe...", nullptr));
        pushButton_test_draw_city->setText(QCoreApplication::translate("MainWindow", "Test draw City", nullptr));
        pushButton_test_add_Street->setText(QCoreApplication::translate("MainWindow", "Test add Street", nullptr));
        checkBox_hide_test->setText(QCoreApplication::translate("MainWindow", "show tests", nullptr));
        pushButton_add_city->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        pushButton_fill_map->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
        pushButton_test_abstract_map->setText(QCoreApplication::translate("MainWindow", "Test Abstract Map", nullptr));
        pushButton_test_dijkstra->setText(QCoreApplication::translate("MainWindow", "Test Dijkstra", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Start:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ziel:", nullptr));
        pushButton_find_fastest_way->setText(QCoreApplication::translate("MainWindow", "Find fastest route", nullptr));
        pushButton_add_street->setText(QCoreApplication::translate("MainWindow", "Add Street", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuScene->setTitle(QCoreApplication::translate("MainWindow", "Scene", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
