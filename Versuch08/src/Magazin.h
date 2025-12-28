#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include "Datum.h"
#include <string>

/**
 * @brief Klasse Magazin
 *
 * Die Klasse Magazin ist von der Basisklasse Medium abgeleitet und erweitert diese
 * um die Eigenschaften Datumausgabe und Sparte
 */
class Magazin : public Medium
{
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte); // Konstruktor

	virtual ~Magazin(); // Destruktor

	virtual void ausgabe(std::ostream& out) const;

	virtual bool ausleihen(Person person, Datum ausleihdatum); // virtual da es schon eine Basis-ausleihen gibt

private :
	Datum datumAusgabe;
	std::string sparte;
};


#endif /* MAGAZIN_H_ */
