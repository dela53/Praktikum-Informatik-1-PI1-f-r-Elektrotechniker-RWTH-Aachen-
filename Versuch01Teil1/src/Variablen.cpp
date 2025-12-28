//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int iErste = 0;
    int iZweite = 0;
    
    // Hier folgt Ihr eigener Code
    cout << "Geben Sie zwei Zahlen ein: " << endl;
    cin >> iErste;
    cin >> iZweite;

    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite;

    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;
    
    double dSummeCast = (double)iErste + iZweite;
    double dQuotientCast = (double)iErste/iZweite;


   cout << "Die gerundete Summe lautet: " << iSumme << "\n" << "Der gerundete Quotient lautet: " <<  iQuotient << "\n\n" <<endl;
   cout << "Die gerundete Summe lautet: " << dSumme << "\n" << "Der gerundete Quotient lautet: " <<  dQuotient << "\n\n" <<endl;
   cout << "Die Summe lautet: " << dSummeCast << "\n" << "Der Quotient lautet: " << dQuotientCast << "\n\n" << endl;

   string sVorname, sNachname;

   cout << "Geben Sie einen Nachnamen ein: " << endl;
   cin >> sNachname;
   sNachname.push_back(' ');
   cout << "Geben Sie einen Vornamen ein: " << endl;
   cin >> sVorname;
   sVorname.push_back(' ');

   string VornameName = sVorname + sNachname;
   string NachnameVorname = sNachname + sVorname;

   cout << "Der Name lautet in Form Vorname Name: " << VornameName << endl;
   cout << "Der Name lautet in Form Nachname Vorname: " << NachnameVorname << endl;

   {
	   int iFeld[2] = {1, 2};
	   cout << "\nFeld iFeld: " << iFeld[0] << iFeld[1] << endl;
   }
   cout << "\n" << endl;
   {
	   int spielfeld[2][3] = {{1, 2, 3},{4, 5, 6}};
	   for (int i = 0; i< 2; i++) {
		   for (int j = 0; j < 3; ++j)  cout << spielfeld[i][j] << " ";
		   cout << "\n" << endl;
		   }
	}
   {
	   const int iZweite = 1;
	   cout << "iZweite innerhalb des Blockes: " << iZweite << "\n" << endl;
   }
     cout << "iZweite außerhalb des Blockes: " << iZweite << "\n" << endl;

     int iName1, iName2;

     iName1 = (int)sVorname[0]; cout << "Erster Buchstabe des Vornahmes in eine Zahl umgewandelt: " << iName1 << "\n" << endl;
     iName2 = (int)sVorname[1]; cout << "Zweiter Buchstabe des Vornahmes in eine Zahl umgewandelt: " << iName2 << "\n" << endl;

     char c1 = sVorname[0];
     char c2 = sVorname[1];

     int pos1 = c1 % 32;
     int pos2 = c2 % 32;

     cout << "Position des 1. Buchstabens im Alphabet: " << pos1 << endl;
     cout << "Position des 2. Buchstabens im Alphabet: " << pos2 << endl;

    return 0;
    
}
