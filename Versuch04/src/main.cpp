//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iostream>
#include <iomanip>
#include <cmath>


/**
* @brief Die main-Funktion berechnet die maximale Sichtweite die ein 1,70 Meter großer Mensch auf einer 555 Meter hohen Plattform steht, bevor die Erdkrümmung dies verhindert
* Leider ist diese Funktion ineffizient
*/
int main()
{
    const double menschGroeße = 0.00170; //in km
	const double plattform = 0.5557; //in km
	const double erdHoehe = 6371; // in km

    //Vektor vector1(1, 0, 0);
    //Vektor vector2(0, 1, 0);

    //vector1.ausgabe();
    //vector2.ausgabe();

    Vektor erdRadius(0, erdHoehe, 0);      // bitte sinnvoll initialisieren
    Vektor aussichtsPunkt(0, erdHoehe + plattform + menschGroeße, 0); // bitte sinnvoll initialisieren
    Vektor sicht = erdRadius.sub(aussichtsPunkt); // Ein Vektor welches die Sicht der Person beschreibt welche anfangs gerade auf dem Boden gerichtet ist und sich nach Winkel ändert.
                                                  // Dabei ist erdRadius.sub(aussichtsPunkt) die Differenz zwischen aussichtsPunkt und erdRadius
    int schritte = 0;
    double gesamtWinkel = 0.0;
    const double beta = 0.0000000001; // in Rad. Je kleiner dieser Wert desto genauer das Ergebnis

    while(erdRadius.winkel(sicht) > 90.0) // bei 90° streift der Sicht-Vektor die Erde nach der Abbildung
    {
    aussichtsPunkt.rotiereUmZ(beta); // Sicht-Vektor wird schrittweise vergrößert
    sicht = erdRadius.sub(aussichtsPunkt); // daraus ein Vektor gemacht
    gesamtWinkel += beta; // inkrementieren Achtung: hier ist der Winkel in Rad. Muss demensprechend in Grad umgewandelt werden
    schritte++;
    }

   double sichtWeite = sicht.laenge(); // Länge des Vektors mit dem Satz des Pythagoras
   double sichtwinkel = gesamtWinkel * (180/M_PI); // größter Winkel umwandeln in Grad

    std::cout << std::fixed << std::setprecision(4); // Ausgabe formatieren
	std::cout << "Sie können " << sichtWeite << " Km weit sehen." << std::endl;
	std::cout << "Sie sind " << (plattform + menschGroeße) * 1000 << " Meter hoch." << std::endl;
	std::cout << "Der Winkel beträgt " << sichtwinkel << " Grad" << std::endl;
	std::cout << "Anzahl Schritte: " << schritte << std::endl;
    return 0;

}
