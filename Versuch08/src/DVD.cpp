#include "DVD.h"
#include <iostream>
#include <string>

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
     : Medium(initTitel), altersFreigabe(initAltersfreigabe), genre(initGenre)
{
	// TODO Auto-generated constructor stub
}

DVD::~DVD()
{
	// TODO Auto-generated destructor stub
}

void DVD::ausgabe(std::ostream& out) const // überladung des << Operators und ausgabe() von der Basisklasse Medium wird überschrieben und individuiert
{
	Medium::ausgabe(out); // Überladene Basisausgabe
	out << "Altersfreigabe: " << altersFreigabe << " Jahre" << std::endl;
	out << "Genre: " << genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	Datum geburtstag = person.getGeburtsdatum();
	int alterInMonaten = ausleihdatum - geburtstag;
	int alterInJahren = alterInMonaten / 12;

	if (alterInJahren < altersFreigabe)
	{
		std::cout << "Die DVD" << titel << "kann nicht an " << person.getName()
				  << "ausgeliehen werden, da die Altersfreigabe: " << altersFreigabe
				  << "nicht erreicht wurde" << std::endl;
		return false; // kann nicht ausgeliehen werden
	}

	return Medium::ausleihen(person, ausleihdatum); // true // ansonsten wird die Basisklasse verwendet
}
