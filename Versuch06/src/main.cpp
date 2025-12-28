/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 6: Dynamische Datenstrukturen
 *
 */

#include "Student.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
    std::vector<Student> studentenListe; // template mit dem Datentyp <Student>
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst füllen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student); // Die member-Funktion in vector heißt push_back
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
        studentenListe.push_back(student);
    }

    do
    {
        std::cout << "\nMenü:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne einfuegen"  << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenbank loeschen" << std::endl
				  << "(6): Datenelement vorne loeschen"<< std::endl
				  << "(7): Datenelement hinten loeschen" << std::endl
				  << "(8): Daten aus einer Datei einlesen" << std::endl
				  << "(9): Daten in eine Datei sichern" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

			// Neuen Student vorne eintragen
			case '2':
			{
				if(!studentenListe.empty())
				{
					std::string name, geburtsdatum, adresse;
					int matNr;

					std::cout << "Name eingeben: " << std::endl;
					std::cin >> name;
					std::cout << "Geburtsdatum eingeben: " << std::endl;
					std::cin >> geburtsdatum;
					std::cout << "Adresse eingeben: " << std::endl;
					std::cin >> adresse;
					std::cout << "Matrikelnummer eingeben: " << std::endl;
					std::cin >> matNr;

					student = Student(matNr, name, geburtsdatum, adresse); // Methode um neuen Student zu erstellen
					studentenListe.insert(studentenListe.begin(), student); // Element wird als vorderstes der Liste eingetragen // @suppress("Invalid arguments")
				}
				else
				{
					std::cerr << "Die Liste ist leer!\n\n";
				}
			}
				break;



            // Datenbank vorwaerts ausgeben
            case '3':
            {
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;

                     for (std::vector<Student>::const_iterator it = studentenListe.begin(); it != studentenListe.end(); ++it)
                     {
                    	 it->ausgabe(); // @suppress("Method cannot be resolved")
                     }
                }
                else
                {
                    std::cerr << "Die Liste ist leer!\n\n";
                }
            }
                break;

            // Datenbank Rückwärts ausgeben
            case '4':
            {
                if(!studentenListe.empty())
				{
					std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;

					for (std::vector<Student>::const_reverse_iterator revit = studentenListe.rbegin(); revit != studentenListe.rend(); ++revit) // rbegin/rend ist nur für reverse
					 {
						 revit->ausgabe(); // @suppress("Method cannot be resolved")
					 }
				}
				else
				{
					std::cerr << "Die Liste ist leer!\n\n";
				}
            }
				break;

            // Student löschen
            case '5':
            {
            	if(!studentenListe.empty())
				{
            		int matNr;
            		bool gefunden = false;
					std::cout << "Matrikelnummer eingeben: ";
					std::cin >> matNr;

				for (std::vector<Student>::iterator it = studentenListe.begin(); it != studentenListe.end()+1; it++) // jeder Eintrag wird einmal durchgegangen
				{
					if (it->getMatNr() == matNr) // @suppress("Method cannot be resolved")
					{
						std::cout << "Der folgende Student wird gelöscht:" << std::endl;
						it->ausgabe(); // @suppress("Method cannot be resolved")
						studentenListe.erase(it); // Student wird gelöscht and der Stelle it // @suppress("Invalid arguments")
						std::cout << "Der Student wurde erfolgreich gelöscht:" << std::endl;
                        gefunden = true;
					}
				}

				if (!gefunden)
				{
					std::cout << "Der Student konnte nicht gefunden werden:" << std::endl;
				}

				else
				{
					std::cerr << "Die Liste ist leer!\n\n";
				}
				}
            }
				break;


			// Datenelement vorne löschen
			case '6':
				{
					if(!studentenListe.empty())
					{
						student = studentenListe.front();
						std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
						student.ausgabe();
						studentenListe.erase(studentenListe.begin()); // @suppress("Invalid arguments")
					}
					else
					{
						std::cerr << "Die Liste ist leer!\n";
					}
				}
				break;

			// Hinterster Student löschen
            case '7':
            {
                if (!studentenListe.empty())
                {
                    std::cout << "Der folgende Student wurde erfolgreich gelöscht:" << std::endl;
                    studentenListe.back().ausgabe();
                    studentenListe.pop_back();
                }
                else
                {
                    std::cerr << "Die Liste ist leer!\n\n";
                }
                break;
            }


            // Öffnet und liest eine Datei
            case '8':
            {
            	int matNr;
            	std::string name, geburtsdatum, adresse, dateiName;

            	std::cout << "Geben Sie den Namen der Datei ein: ";
            	std::cin >> dateiName;
            	std::ifstream datei(dateiName); // öffnet die Datei zum Lesen
            	studentenListe.clear();

            	if (!datei.is_open()) // falls die Datei nicht öffnet, soll eine Fehlermeldung ausgegeben werden
            	{
            		std::cerr << "\nFehler beim Oeffnen der Datei! " << std::endl; // cerr ist eine standard-Fehlerausgabenfunktion von iostream. Ausgabe in rot
            		break;
            	}
            	else
            	{
            		std::cout << "Datei wurde erfolgreich geöffnet.\n" << std::endl;
            	}
            		while (!datei.eof()) // während die Datei geöffnet ist. eof = end of file
            		{
            			datei >> matNr; // Daten aus der Datei lesen. getline ist nur für strings

            			if (datei.fail()) break;  // Wenn keine Matrikelnummer gefunden wurde Schleife beenden

            			datei.ignore(10000000, '\n'); // ignoriert Zeilenumbrüche der Zeilen

            			std::getline(datei, name); // Name lesen
            			std::getline(datei, geburtsdatum); // Geburtsdatum lesen
            			std::getline(datei, adresse);  // Adresse lesen
            			std::cout << matNr << "\n" << name << "\n" << geburtsdatum << "\n" << adresse << "\n\n";

            			Student student(matNr, name, geburtsdatum, adresse); // Neues Element wird erstellt
            			studentenListe.push_back(student); // Element wird am Ende hinzugefügt
            			}

						std::cout << "Die Daten wurden erfolgreich eingelesen.\n";
						datei.close(); // Datei wird geschlossen
						break;
            }

            // Daten in einer Datei sichern
            case '9':
            {
            	std::string name, geburtsdatum, adresse, dateiName;
            	std::cout << "Geben Sie den Namen der Datei ein: ";
            	std::cin >> dateiName;

            	std::ofstream datei(dateiName); // Datei wird schreibfähig geöffnet

            	for (std::vector<Student>::iterator student = studentenListe.begin(); student != studentenListe.end(); student++) // Geht die Liste durch
            	{
            		datei << student->getMatNr() << "\n"; // @suppress("Method cannot be resolved") // Gibt den Funktionen die Referenz des Objekts Student
					datei << student->getName() << "\n"; // @suppress("Method cannot be resolved")
					datei << student->getGeburtstag() << "\n"; // @suppress("Method cannot be resolved")
					datei << student->getAdresse() << "\n"; // @suppress("Method cannot be resolved")
            	}

            	std::cout << "Die Daten wurden erfolgreich gespeichert.\n";
				datei.close(); // Datei wird geschlossen
                break;
            }
            // Programm wird beendet
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cerr << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
