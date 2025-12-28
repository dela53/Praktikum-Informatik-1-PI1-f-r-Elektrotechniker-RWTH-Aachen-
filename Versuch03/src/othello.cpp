/**
 * Praktikum Informatik 1
 *
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cerr << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld. Der enstprechende Gewinner mit den meisten Steinen wird mit der Nummer 1 oder 2 zurückgegeben.
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
	 // Hier erfolgt jetzt Ihre Implementierung ...
    if (posX >= GROESSE_X || posY >= GROESSE_Y || posX < 0 || posY < 0)
    return false;

    else return true;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Danach wird solange zurückgegangen bis man zur ursprünglichen Position ankommt.
 *  Dabei werden die gegnerischen Steine zur eigenen bei jedem Schritt umgewandelt.
 *  Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...
        	if (i == 0 && j == 0) continue; // Notitz: j = 0 und i = 0 keine Richtungsänderung bzw. gleiche Position| j = y-Richtung / i = x-Richtung / -1 links/oben 1 rechts/unten

        	int x = posX + i;
        	int y = posY + j;

        	if (spielfeld[y][x] != gegner || aufSpielfeld(x, y) == false) continue; // Wenn der Stein auf dem Feld des Gegners oder außerhalb des Feldes ist, ist der Zug ungültig.

        	x += i;     // Richtung wird fortgeführt bis Gegnersteine erreicht werden
        	y += j;

        	while (aufSpielfeld(x,y))
        	{
        		if (spielfeld[y][x] == 0) break; // Das Feld ist leer, d.h Zug ist ungültig
        		else if (spielfeld[y][x] == aktuellerSpieler) return true; // Zug ist Gültig, wenn der Stein von aktuellerSpieler gefunden wurde.

        		 x += i; // inkrementieren und weiter überprüfen.
        		 y += j;
        	}
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt.
 * Diese Funktion ist ähnlich wie zugGueltig, nur dass sie zusätzlich die gegnerischen Steine umdreht, wenn sie zwischen den Steinen des aktuellen Spielers liegen.
 * Detail: Allerdings wird der Stein gesetzt nachdem alle gegnerischen Steine umgewandelt wurden.
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    //Alle Richtungen bearbeiten / Diese Schleife beschreibt alle 8 richtungen die nacheinander abgearbeitet werden.
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...
        	if (i == 0 && j == 0) continue; // i == 0 && j == 0 wird übersprungen da es keine Richtung beschreibt.

			int x = posX + i;               // Richtung wird überprüft
			int y = posY + j;               //

			if (spielfeld[y][x] != gegner || aufSpielfeld(x, y) == false) continue;  // Richtung wird ignoriert sobald kein gegnischer Stein benachbart ist oder man nicht mehr im Feld ist.

			x += i; // Weiter in dieser richtung gehen.
			y += j;

			while (aufSpielfeld(x,y)) // solange man im Feld ist:
			{
				if (spielfeld[y][x] == gegner) // wird die Richtung weitergegangen bis kein gegnerischer Stein mehr da ist bzw. man auf einem eigenen Stein trifft. Sonst wird abgebrochen.
				{
				 x += i;
				 y += j;
				}

				else if (spielfeld[y][x] == aktuellerSpieler) // findet man sein eigenen Stein:
				{
					while (x != posX || y != posY) // so wird zurückgegangen bis man wieder zurück zur Anfangsposition ankommt. Dabei werden alle gegnerischen Steine zur eigenen Steine umgewandelt.
					{
					 x -= i;
					 y -= j;
					 spielfeld[y][x] = aktuellerSpieler; // Alle Steine werden zu eigenen Steinen umgewandelt.
					}

					break;
				}
				else
				{
					break;
				}
        	 }
          }
        }
    spielfeld[posY][posX] = aktuellerSpieler; // Eigener Stein wird im ursprünglichen (ausgewählten) Position des Feldes gesetzt. (Damit die Logik der schleifen nicht zerstört werden)
    }


/** Gibt die Menge (int) der gültigen Züge anhand der Funktion zugGültig() und gibt diese aus.
*/
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	int mengeDerZüge = 0;

	for (int j = 0;  j < GROESSE_Y; j++) // Geht durch alle Felder durch bzw. durch alle 8 Richtungen.
	{
		for (int i = 0; i < GROESSE_X; i++)
		{
		  if (zugGueltig(spielfeld, aktuellerSpieler, i, j)) ++mengeDerZüge; // Inkrementiert die Menge der Züge wenn Zug gültig ist.
		}
	}

    return mengeDerZüge;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cerr << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}

/**
 * Die Funktion spielen() ermöglicht Spieler 1 und Spieler 2 abwechselnd einen Zug zu machen.
 * Dabei wird getestet, ob Züge für den jeweiligen Spieler noch möglich sind.
 * Wenn der Spieler keinen Zug mehr hat, muss er einmal aussetzen.
 * Haben alle Spieler keine Züge mehr, wird das Spiel sofort beendet.
 * Schließlich wird der Gewinner bekannt.
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    int keineZuege = 0;

    while (keineZuege < 2)
    {
    	if (moeglicheZuege(spielfeld, aktuellerSpieler) > 0)
    	{
    		keineZuege = 0; // Zähler wird zurückgesetzt, da der Spieler ein Zug durchführen konnte
    		if (spielerTyp[aktuellerSpieler - 1] == MENSCH) // Ist der eingegebene Spieler (in main) ein Mensch ist Spieler 2 ein Mensch, sonst ist er ein Computer
		{
        menschlicherZug(spielfeld, aktuellerSpieler);
    	zeigeSpielfeld(spielfeld);
		}
    		else if (spielerTyp[aktuellerSpieler - 1] == COMPUTER)
    		{
    			computerZug(spielfeld, aktuellerSpieler);
    			zeigeSpielfeld(spielfeld);
    		}

    	}
    	else
    	{
    		std::cout << "Spieler " << aktuellerSpieler << " kann keinen Zug machen und muss aussetzen.\n";
    		++keineZuege;
    	}
    	aktuellerSpieler = 3 - aktuellerSpieler; // Spielerwechsel von Spieler 1 zu Spieler 2
    }

    std::cout << "Spiel ist zu Ende!" << std::endl;

    switch (gewinner(spielfeld)) //Bekanntgabe des Gewinners
    {
        // Hier erfolgt jetzt Ihre Implementierung ...
    case (0):
		std::cout << "Unentschieden!" << std::endl;
		break;
    case (1):
		std::cout << "Spieler 1 (X) hat gewonnen!" << std::endl;
		break;
    case (2):
		std::cout << "Spieler 2 (O) hat gewonnen!" << std::endl;
		break;

    }
}

int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cerr << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }

    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COMPUTER(=2)
    // spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ... #int spielerTyp [2] = { MENSCH , MENSCH };
    Auswahl:
    int menschOderComputer = 0;
    std::cout << "Mensch = 1 / COM = 2 / COM vs COM = 3 Eingabe: ";
    std::cin >> menschOderComputer;
    if (menschOderComputer == 1) //extra
    {
         int spielerTyp [2] = {MENSCH,MENSCH};
    	 spielen (spielerTyp);
    }
    else if (menschOderComputer == 2)
    {
    	int spielerTyp [2] = {MENSCH,COMPUTER};
    	spielen (spielerTyp);
    }
    else if (menschOderComputer == 3)
       {
       	int spielerTyp [2] = {COMPUTER,COMPUTER};
       	spielen (spielerTyp);
       }

    else
    	{
    		std::cerr << "\nEingabe ist ungültig. Wiederhole die Eingabe. ";
    		goto Auswahl;
    	}

    return 0;
 }
