#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h" // Medium.h mit einbeziehen für Vererbung
#include <string>


/**
 * @brief Klasse Buch
 *
 * Die Klasse Buch ist von der Basisklasse Medium abgeleitet und ergänzt diese
 * um die Eigenschaft Autor.
 */
class Buch : public Medium // Vererbung der Klasse Medium
{
public:

	Buch(std::string initTitel, std::string initAutor);

	virtual ~Buch(); // Destruktor

	virtual void ausgabe(std::ostream& out) const; // ohne virtual wird nur Medium ausgegeben

private:
	std::string autor;
};

#endif /* BUCH_H_ */
