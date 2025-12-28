/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

typedef struct Person {
	std::string sNachname;
	std::string sVorname;
	int iGeburtsjahr, iAlter;
} person;

int main()
{
	person nBenutzer;

	cout << "Geben Sie einen Nachnamen ein: ";
	cin >> nBenutzer.sNachname;
	cout << "Geben Sie einen Vornamen ein: ";
	cin >> nBenutzer.sVorname;
	cout << "Geben Sie das Geburtsjahr ein: ";
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Geben Sie das Alter ein: ";
	cin >> nBenutzer.iAlter;

	cout << "\n\nBenutzername: " << nBenutzer.sNachname << " " << nBenutzer.sVorname << "\nAlter: " << nBenutzer.iAlter <<  "\nGeburtsjahr: " << nBenutzer.iGeburtsjahr << endl;
    
    person nKopieEinzeln;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	person nKopieGesamt = nBenutzer; // ist einafcher und kompakter als einzeln zu kopieren

	cout << "\nName: " << nKopieEinzeln.sNachname << " " << nKopieEinzeln.sVorname << endl;
	cout << "Alter: " << nKopieEinzeln.iAlter << endl;
	cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << endl;

	cout << "\nName: " << nKopieGesamt.sNachname << " " << nKopieGesamt.sVorname << endl;
	cout << "Alter: " << nKopieGesamt.iAlter << endl;
	cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << endl;

    return 0;
}
