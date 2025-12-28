/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 7: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Student.h"

//aus Git
#define RED     "\033[31m"      // Red
#define GREEN   "\033[32m"      // Green
#define RESET   "\033[0m"       // zum Zurücksetzten der Farbe zur Standard bzw. weiß


int main()
{

    std::vector<Student> studentenListe; // template mit dem Datentypen <Student>
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst füllen?"; std::cout << GREEN << " (j)" << RESET << "/" << RED << "(n) " << RESET << std::endl;
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
                  << "(1): Datenelement hinten hinzufügen" << std::endl
                  << "(2): Datenelement vorne einfügen"  << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenelement löschen" << std::endl
				  << "(6): Datenelement vorne löschen"<< std::endl
				  << "(7): Datenelement hinten löschen" << std::endl
				  << "(8): Daten aus einer Datei einlesen" << std::endl
				  << "(9): Daten in eine Datei sichern" << std::endl
				  << "(o): Datenbank aufsteigend sortieren" << std::endl
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

                    std::cout << "Bitte geben sie die Daten für den Studenten ein\nName: ";
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
					std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:\n" << std::endl;

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

					std::cout << "Matrikelnummer eingeben: ";
					std::cin >> matNr;

					// durchsucht die Liste und vergleicht die geg. Matrikelnummer mit jedem einzelnen Eintrag. Diese Funktion verwendet den überladenen Gleichoperator
					auto it = std::find(studentenListe.begin(),studentenListe.end(), matNr); // @suppress("Function cannot be instantiated")

					if(it != studentenListe.end()) // verhindert, dass it willkürlich auf end zeigt. Das passiert, wenn der Student nicht gefunden wurde
					{
					std::cout << "Der folgende Student wird gelöscht:\n" << std::endl;
					it->ausgabe(); // @suppress("Method cannot be resolved")
					studentenListe.erase(it); // Student wird gelöscht and der Stelle it // @suppress("Invalid arguments")
					std::cout << GREEN << "\nDer Student wurde erfolgreich gelöscht." << RESET << std::endl;
					}
					else
					{
						std::cerr << "Der Student konnte nicht gefunden werden." << std::endl;
					}
				}
				else
				{
					std::cerr << "Die Liste ist leer!" << std::endl;
				}

				break;
            }

			// Datenelement vorne löschen
			case '6':
				{
					if(!studentenListe.empty())
					{
						student = studentenListe.front();
						std::cout << "Der folgende Student ist gelöscht worden:" << std::endl;
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
            		std::cerr << "\nFehler beim Öffnen der Datei! " << std::endl; // cerr ist eine standard-Fehlerausgabenfunktion von iostream. Ausgabe in rot
            		break;
            	}
            	else
            	{
            		std::cout << GREEN << "\nDatei wurde erfolgreich geöffnet.\n" << RESET << std::endl;
            	}
            		while (!datei.eof()) // während die Datei geöffnet ist. eof = end of file
            		{
            			datei >> matNr; // Daten aus der Datei lesen. getline ist nur für strings

            			if (datei.fail()) break;  // Wenn keine Matrikelnummer gefunden wurde Schleife beenden

            			datei.ignore(10000000, '\n'); // ignoriert Zeilenumbrüche der Zeilen
            			std::getline(datei, name); // Name lesen
            			std::getline(datei, geburtsdatum); // Geburtsdatum lesen
            			std::getline(datei, adresse);  // Adresse lesen
            			//std::cout << matNr << "\n" << name << "\n" << geburtsdatum << "\n" << adresse << "\n\n"; alte Methode
            			Student student(matNr, name, geburtsdatum, adresse); // Neues Element wird erstellt
            			std::cout << student; // neue Methode mit dem überladenden Operator
            			studentenListe.push_back(student); // Element wird am Ende hinzugefügt
            			}

						std::cout << GREEN << "\nDie Daten wurden erfolgreich eingelesen.\n" << RESET;
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

            	std::cout << GREEN << "Die Daten wurden erfolgreich gespeichert\n" << RESET;
				datei.close(); // Datei wird geschlossen
                break;
            }

            // Liste absteigend sortieren
            case 'o':
            {
            	std::sort(studentenListe.begin(), studentenListe.end()); // @suppress("Invalid arguments") // Sortiert Liste von Anfang bis Ende
            	std::cout << "Studenten wurden sortiert:\n";

            	for (std::vector<Student>::const_iterator it = studentenListe.begin(); it != studentenListe.end(); it++)
            	{
            		std::cout << *it << "\n"; // it muss Zeiger sein weil it eig. ein Objekt ist. It würde sich selber übergeben ohne Zeiger
            	}

            	break;
            }
            // Programm wird beendet
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default:
                std::cerr << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
