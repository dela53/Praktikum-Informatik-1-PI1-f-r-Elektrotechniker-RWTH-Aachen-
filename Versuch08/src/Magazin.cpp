#include "Magazin.h"
#include <iostream>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
       : Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte)
{
	// TODO Auto-generated constructor stub
}

Magazin::~Magazin()
{
	// TODO Auto-generated destructor stub
}

void Magazin::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
	out << "Erscheinungsdatum: " << datumAusgabe << std::endl; // Überladung von << Operator
	out << "Sparte: " << sparte << std::endl; // überladen von << Operator
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)

{
	int monatDiff = ausleihdatum - ausleihdatum; // Minus Operator wurde überladen. Zwei Datum Objekte werden von Tag/Monat differenziert.

	if (monatDiff >= 0)
	{
		std::cout << "Das Magazin" << titel << "kann nicht an " << person.getName() << "ausgeliehen werden, da das Magazin noch nicht 1 Monat alt ist. " << std::endl;
		return false; // kann nicht ausgeliehen werden
	}

	return Medium::ausleihen(person, ausleihdatum); // Ansonsten wird die Basisklasse verwendet // true
}
