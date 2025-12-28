//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    void ausgabe() const;
    // Es wird ein Operator defeniert, welches mit dem Typ Student vergleicht
    bool operator<(const Student& other_Student) const; // Es wird ein < Operator defeniert welches constant bzw. nicht verändert wird.
    bool operator>(const Student& other_Student) const; // Die Referenz auf Student bleibt auch konstant bzw. sie verändert sich nicht.
    bool operator==(const Student& other_Student) const; // other-Student ist der Name des Objekts das verglichen wird
    void ausgabe(std::ostream& out) const; // Neue Methode für gebündelte und konstante Ausgabe


private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

std::ostream& operator<<(std::ostream& out, const Student& student); // Neue Methode für eine überladene Ausgabe

bool operator==(const Student& other_Student, const int matNr); // Neue Methode zu vergleichen von zwei Matrikelnummern von zwei Studenten

#endif
