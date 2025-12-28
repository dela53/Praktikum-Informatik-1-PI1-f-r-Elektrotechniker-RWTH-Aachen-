#ifndef DVD_H_
#define DVD_H_

#include <string>
#include "Magazin.h"
#include "Datum.h"

/**
 * @brief Klasse DVD
 *
 * Die Klasse DVD ist von der Basisklasse Medium abgeleitet und erweitert diese
 * um die Eigenschaften Altersfreigabe und Genre
 */
class DVD : public Medium // Vererbung von Medium
{
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre); // Konstruktor
	virtual ~DVD(); // Destruktor

	virtual void ausgabe(std::ostream& out) const; // "virtual" damit die Laufzeit bestimmt, welche Ausgabe erfolgt

	virtual bool ausleihen(Person person, Datum ausleihdatum);

private:
int altersFreigabe;
std::string genre;
};

#endif /* DVD_H_ */
