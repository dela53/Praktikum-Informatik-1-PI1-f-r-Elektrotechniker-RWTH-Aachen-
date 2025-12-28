#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "dialog.h"
#include "mapio.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "addstreet_dialog.h"
#include "mapiofileinput.h"

#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QFileDialog>

// Glabale Variablen, damit sie überall angewendet werden können
City* city1 = new City("Köln", 100, 100);
City* city2 = new City("Bonn", 100, 200);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menuBar()->setNativeMenuBar(false); // Menüleiste wird angezeigt

    scene = new QGraphicsScene(this); // This Zeiger wegen automatische Speicherverwaltung
    ui->graphicsView->setScene(scene); // Objekt wird angezeigt bei ausführen der Datei

    map = new Map;
    fill = new MapIoNrw;

    // Tests werden als Standard deaktiviert bzw. versteckt
    ui->pushButton_teste_was->hide();
    ui->pushButton_test_draw_city->hide();
    ui->pushButton_test_add_Street->hide();
    ui->pushButton_test_abstract_map->hide();
    ui->pushButton_test_dijkstra->hide();
    ui->lineEdit_teste_was->hide();

    qDebug() << "Neues Projekt gestartet.";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    QString str = ui->lineEdit_teste_was->text();
    QString ausgabetext;
    bool esIstEineZahl;
    int zahl = str.toInt(&esIstEineZahl);

    if (esIstEineZahl)
    {
        zahl += 4;
        ausgabetext = QString("Die eingegebene Zahl erhöht um 4 ergibt %1").arg(zahl);
        qDebug() << ausgabetext;
    }
    else
    {
    ausgabetext = QString("Der Benutzer hat folgendes eingetippt: %1").arg(str);
    qDebug() << ausgabetext;
    }
    QMessageBox msgBox; // Objekt vom Typ QMessageBox
    msgBox.setText(ausgabetext); // Speichert den Text im Objekt
    msgBox.exec(); // blendet die Massage-Box ein

    int x = QRandomGenerator::global()->bounded(100);
    int y = QRandomGenerator::global()->bounded(100);
    int w = QRandomGenerator::global()->bounded(100);
    int h = QRandomGenerator::global()->bounded(100);

    scene->addRect(x, y, w, h, QPen(Qt::red), QBrush(Qt::blue));

}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    // Alles zurücksetzen inklusive Liste für Dijkstra
    scene->clear();
    ui->comboBox_start_city->clear();
    ui->comboBox_end_city->clear();

    delete map;
    map = new Map();  // Leere neue Karte erzeugen
    qDebug() << "Szene und Karte wurden komplett geleert.";
}



void MainWindow::on_actionAbout_triggered()
{
    QString info = "Streetplaner\n"
                   "Version 1.0\n\n"
                   "Copyright (c) 2025 Dela-53® Company Ltd\n"
                   "Alle Rechte vorbehalten\n\n"
                   "Erstellt mit Qt."; // Typische Beschreibung

    QMessageBox msgBox; // Objekt vom Typ QMessageBox
    msgBox.about(this, "Über dieses Programm", info);
}


void MainWindow::on_pushButton_test_draw_city_clicked()
{
    city1->draw(*scene); // Zeiger auf Objekt QGraphicsScene
    city2->draw(*scene); // auch...

    map->addCity(city1);
    map->addCity(city2);
}



void MainWindow::on_pushButton_test_add_Street_clicked()
{
    // Städte zur Karte hinzufügen
    map->addCity(city1);
    map->addCity(city2);


    Street* street1 = new Street(city1, city2);// Straße zwischen den beiden Städten erzeugen


    if (map->addStreet(street1)) // Straße zur Karte hinzufügen falls true
    {
        qDebug() << "Straße erfolgreich hinzugefügt.";
    }
    else
    {
        qDebug() << "Straße konnte nicht hinzugefügt werden.";
    }

    // Karte neu zeichnen
    map->draw(*scene);
}




void MainWindow::on_checkBox_hide_test_clicked()
{
    bool checked = ui->checkBox_hide_test->isChecked(); // Variable für Abfrage vom Status der Checkbox

    if (checked) // Wenn aktiviert, dann werden die Tests gezeigt
    {
        ui->pushButton_teste_was->show();
        ui->pushButton_test_draw_city->show();
        ui->pushButton_test_add_Street->show();
        ui->pushButton_test_abstract_map->show();
        ui->pushButton_test_dijkstra->show();
        ui->lineEdit_teste_was->show();
    }

    else
    {
        ui->pushButton_teste_was->hide();
        ui->pushButton_test_draw_city->hide();
        ui->pushButton_test_add_Street->hide();
        ui->pushButton_test_abstract_map->hide();
        ui->pushButton_test_dijkstra->hide();
        ui->lineEdit_teste_was->hide();
    }
}


void MainWindow::on_pushButton_add_city_clicked()
{
  while (true) // Schleife damit Dialog automatisch wieder geöffnet wird.
  {
    Dialog dialog(this); // Instatz auf Dialog
    int result = dialog.exec(); // Hauptfenster wird blockiert bis man den Dialog abgeschlossen hat // int damit es mehrere Ergebnisse geben kann

    if (result == QDialog::Accepted) // stadt hinzufügen // QDialog::Accepted gibt 1 zurück
    {
        City* newCity = dialog.generateCity();

        if (newCity) // wenn true dann wurde die Eingabe akzeptiert
        {
            map->addCity(newCity);
            map->draw(*scene);

            // Liste mit der neuen Stadt für Dijkstra füllen
            ui->comboBox_start_city->addItem(newCity->getName());
            ui->comboBox_end_city->addItem(newCity->getName());
            qDebug() << "Eingabe wurde akzeptiert";
            break; // Raus aus der Schleife
        }
        else
        {
            continue; // Dialog erneut anzeigen bzw. Schleife wird nicht abgebrochen
        }
    }

    else // abbrechen und nichts machen
    {
        qDebug() << "Dialog wurde abgebrochen";
        break;
    }
  }
}


void MainWindow::on_pushButton_fill_map_clicked()
{
    if (map && fill)
    {
        fill->fillMap(*map);
        map->draw(*scene);
    }
    else
    {
        QMessageBox::warning(this, "Fehler.", "Daten werden nicht erkannt");
        qDebug() << "Fehler. Daten wurden nicht korrekt initialisiert.";
    }

    // Falls davor was ist wird die Liste zurückgesetzt
    ui->comboBox_start_city->clear();
    ui->comboBox_end_city->clear();

    // Liste mit allen vorprogrammierten Städten für Dijkstra füllen
    for (City* city : map->getCityList())
    {
        ui->comboBox_start_city->addItem(city->getName());
        ui->comboBox_end_city->addItem(city->getName());
    }
}


void MainWindow::on_pushButton_test_abstract_map_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = map->findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = testMap.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButton_test_dijkstra_clicked()
{
    QVector<Street*> fastestWay = Dijkstra::search(*map, "Düsseldorf", "Bonn");

    if (fastestWay.isEmpty()) // is Empty da es eine Liste ist
    {
        qDebug() << "Weg wurde nicht gefunden";
        QMessageBox::warning(this, "Fehler:", "Weg wurde nicht gefunden. Bitte fügen Sie ggf. mehr Strassen hinzu.");
    }

    for (const auto street : fastestWay)
    {
        street->drawRed(*scene); // Schnellste Straße bzw. kürzeste Straße wird gezeichnet.
    }

    qDebug() << "Weg gefunden mit" << fastestWay.size() << "Straßen."; // Menge der Strassen wird ausgegeben
}


void MainWindow::on_pushButton_find_fastest_way_clicked()
{

    if (map->getCityList().size() < 2) // Verhindert das Öfnen des Dialoges, wenn sich weniger als zwei Städte in der Karte befinden
    {
        QMessageBox::warning(this, "Fehler", "Es müssen mindestens zwei Städte vorhanden sein, um eine Straße zu erstellen.");
        return;
    }

    // Ausgewählte Städte aus der Liste (Widget)
    QString startCityName = ui->comboBox_start_city->currentText();
    QString endCityName = ui->comboBox_end_city->currentText();

    // überprüfen ob zwei Städte ausgewählt wurden
    if (startCityName.isEmpty() || endCityName.isEmpty())
    {
        qDebug() << "Stadt konnte nicht ausgewählt werden";
        QMessageBox::warning(this, "Warnung:", "Fehler: Es wurde mind. eine Stadt nicht ausgewählt.");
        return;
    }
    // Schleife um zu verhindern, dass mit identischen Städten gearbeitet wird. // Ohne diese Schleife würde das Programm abstürzen
    else if (startCityName == endCityName)
    {
        qDebug() << "Fehler: Ausgewählte Städte sind gleich";
        QMessageBox::warning(this, "Fehler:", "Fehler: Ausgewählte Städte sind gleich");
        return;
    }

    QVector<Street*> fastestWay = Dijkstra::search(*map, startCityName, endCityName); // Dijkstra Algorithmus Aufruf

    if (fastestWay.isEmpty()) // is Empty da es eine Liste ist
    {
        qDebug() << "Weg wurde nicht gefunden";
        QMessageBox::warning(this, "Fehler:", "Weg wurde nicht gefunden. Bitte fügen Sie ggf. mehr Strassen hinzu.");
    }

    for (const auto street : fastestWay)
    {
        street->drawRed(*scene); // Schnellste Straße bzw. kürzeste Straße wird gezeichnet.
    }

    qDebug() << "Weg gefunden mit" << fastestWay.size() << "Straßen."; // Menge der Strassen wird ausgegeben
}


void MainWindow::on_pushButton_add_street_clicked()
{
    if (map->getCityList().size() < 2) // Verhindert das Öfnen des Dialoges, wenn sich weniger als zwei Städte in der Karte befinden
    {
        QMessageBox::warning(this, "Fehler", "Es müssen mindestens zwei Städte vorhanden sein, um eine Straße zu erstellen.");
        return;
    }

    while (true) // Schleife damit Dialog automatisch wieder geöffnet wird.
    {
        addstreet_dialog dialog(map->getCityList(), this); // Instatz auf Dialog //Konstruktor hat zwei Argumente
        int result = dialog.exec(); // Hauptfenster wird blockiert bis man den Dialog abgeschlossen hat // int damit es mehrere Ergebnisse geben kann

        if (result == QDialog::Accepted) // stadt hinzufügen // QDialog::Accepted gibt 1 zurück
        {
            Street* newStreet = dialog.generateStreet(map);

            if (newStreet) // wenn true dann wurde die Eingabe akzeptiert
            {
                map->addStreet(newStreet);
                map->draw(*scene);
                qDebug() << "Eingabe wurde akzeptiert";
                break; // Raus aus der Schleife
            }
            else
            {
                QMessageBox::warning(this, "Fehler:", "Fehler: Start- oder Zielstadt wurden nicht ausgewählt oder sind gleich.");
                continue; // Dialog erneut anzeigen bzw. Schleife wird nicht abgebrochen
            }
        }

        else // abbrechen und nichts machen
        {
            qDebug() << "Dialog wurde abgebrochen";
            break;
        }

    }
}


void MainWindow::on_actionOpen_city_file_triggered()
{   // öffnet ein Dialog indem man die Datei auswählen kann
    QString cityFileName = QFileDialog::getOpenFileName(this, "Städte-Datei auswählen", "", "Textdateien (*.txt)");
    if (cityFileName.isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte geben Sie einen gültigen Pfad zur Datei ein.");
        return;
    }

    // öffnet ein Dialog indem man die Dataie auswählen kann
    QString streetFileName = QFileDialog::getOpenFileName(this, "Straßen-Datei auswählen", "", "Textdateien (*.txt)");
    if (streetFileName.isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte geben Sie einen gültigen Pfad zur Datei ein.");
        return;
    }

    // alles zurücksetzen
    scene->clear();
    delete map;
    map = new Map();


    MapIoFileinput* fileLoader = new MapIoFileinput(cityFileName, streetFileName); // ruft den Konstruktor von MapIoFileinput auf bzw. öffnet die Datei
    fileLoader->fillMap(*map); // Zeiger auf Map // füllt die Karte bzw. Liste mit neuen Daten auf.
    map->draw(*scene); // zeichnet die Karte als Grafik
    delete fileLoader; // es wird nicht mehr gebraucht

    // aktualisiert die ComboBox bz.w setzt sie zurück
    ui->comboBox_start_city->clear();
    ui->comboBox_end_city->clear();

    for (City* city : map->getCityList()) // füllt die ComboBox wieder auf.
    {
        ui->comboBox_start_city->addItem(city->getName());
        ui->comboBox_end_city->addItem(city->getName());
    }

    qDebug() << "Karte erfolgreich geladen.";
    QMessageBox::information(this, "Datei", "Dateien wurden erfolgreich geöffnet");
}
