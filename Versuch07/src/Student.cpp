//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe() const
{
    std::cout << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl;
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer (<)
 * @return true, wenn die eigene Matrikelnummer kleiner ist, andernfalls false.
 */
bool Student::operator<(const Student& other_Student) const
{
    return matNr < other_Student.matNr;
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer (>)
 * @return true, wenn die eigene Matrikelnummer größer ist, andernfalls false.
 */
bool Student::operator>(const Student& other_Student) const
{
    return matNr > other_Student.matNr;
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer (=)
 * @return true, wenn die eigene Matrikelnummer gleich ist, andernfalls false.
 */
bool Student::operator==(const Student& other_Student) const
{
    return matNr == other_Student.matNr;
}

/**
 * @brief Gibt die Daten des Students gebündelt aus
 *
 * Die Ausgabe ist konstant und gebündelt und einfacher zu bedienen
 */
void Student::ausgabe(std::ostream& out) const // Ausgabe immer konstant //überladen
{
out << "\nName: " << name << "\n"
	    << "Geburtstag: " << geburtstag << "\n"
	    << "Adresse: " << adresse << "\n"
	    << "Matrikelnummer: " << matNr << "\n\n\n";
}

/**
 * @brief Vergleicht zwei Studenten anhand ihrer Matrikelnummer(=). Unterschied: Überladung mit zwei Parametern für die find Funktion
 * @return true, wenn die eigene Matrikelnummer gleich ist, andernfalls false.
 */
bool operator==(const Student& other_Student, const int matNr)
{
     return matNr == other_Student.getMatNr(); // getMatNr() nötig da matNr private ist
}

/**
 * @brief Überladener Ausgabeoperator für die Klasse Student
 *
 * Überladung: Einer Funktion oder einem Operator mehrere Bedeutungen zu geben, abhängig von den Argumenten
 * Ermöglicht die direkte Ausgabe eines Student-Objekts mit dem << Operator,
 * z.B. std::cout << student;
 */
std::ostream& operator<<(std::ostream& out, const Student& student) // vereinfachen bzw. weniger Aufwand beim ausgeben
{
	student.ausgabe(out);
	return out;
}








