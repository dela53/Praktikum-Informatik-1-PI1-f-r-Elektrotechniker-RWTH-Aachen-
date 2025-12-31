//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Vektor.h"
#include <cmath>

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
/**
 * @brief Die Funktion berechnet den Betrag bzw. die Länge des Vektors mit dem Satz des Pythagoras und gibt diese aus
 */
double Vektor::laenge() const
{
	return std::sqrt(x*x+y*y+z*z); /// Formel: √x^2+y^2+z^2
}

/**
 * @brief Die Funktion berechnet die Differenz zwischen den Vektoren und gibt diese aus
 */
Vektor Vektor::sub(const Vektor& input) const   // Vektor, da es drei Koordinaten gibt
{
	return Vektor(x-input.x, y-input.y, z-input.z);
}

/**
 * @brief Die Funktion berechnet den Skalarprodukt zweier Vektoren und gibt diese aus
 */
double Vektor::skalarProd(const Vektor& input) const
{
	return (x*input.x + y*input.y + z*input.z);
}

/**
 * @brief Die Funktion berechnet den Winkel zweier Vektoren und benutzt dafür andere Konstruktionen. Den Winkel gibt die Funktion in Grad aus
 */
double Vektor::winkel(const Vektor& input) const
{
	double betragVektor = laenge();
	double betragVektorInput = input.laenge();
	double skalar = skalarProd(input);
	double cosinus = skalar/(betragVektor*betragVektorInput);
	double winkelInRad = std::acos(cosinus);

	return winkelInRad * (180 / M_PI);
}

/**
 * @brief Diese Funktion rotiert den Vektor um die z-Achse. Sie benutzt dazu temporäre Variablen um dies realisieren zu können. Sie gibt nichts aus (void)
 */
void Vektor::rotiereUmZ(const double rad)
{
	double rotX = x * std::cos(rad) - y * std::sin(rad); // Die Formel erhält man durch das Ausmultiplizieren der Matrizen in 4.6.1
	double rotY = x * std::sin(rad) + y * std::cos(rad); //

	x = rotX; // Da x und y noch werwendet werden mussten, brauchte man rotX und rotY als Zwischenspeicherung für die neuen Werte.
	y = rotY; //
}

