//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"
#include <iostream>

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData) // fügt hinten bzw. am Ende ein neues Element ein hinzu
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr); // beide Pointer prev und next müssen bei einer neuen Liste auf null zeigen

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else // Liste ist nicht leer. Back zeigt auf das letzte Element. Es muss aber auf nullptr zeigen
    {
        back->setNext(neuesElement); // ein neues Element wird hinten hinzugefügt. Damit Element nicht verloren geht, muss der Next-Zeiger des nicht aktualisierten backs auf das neue Element zeigen
        neuesElement->setPrev(back); // neues Element wird jetzt als vorheriges von back gesetzt. prev-Zeiger von neues Element zeigt auf back
        back = neuesElement; // neustes Element ist jetzt back

    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
	ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr); // beide Pointer prev und next müssen bei einer neuen Liste auf null zeigen

	if (front == nullptr)                                       // Liste leer?
	    {
	        front = neuesElement;
	        back = neuesElement;
	    }
	else
	{
		front->setPrev(neuesElement); // prev Zeiger von front zeigt jetzt auf neuesElement
		neuesElement->setPrev(nullptr);
		neuesElement->setNext(front);// prev Zeger von neuesElement zeigt auf null
		front = neuesElement; // neuesElement ist jetzt front, weil es am vordersten ist
	}
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront() // Methode löscht vorderstes Element der Liste
{
    ListenElement* cursor = front;                           // cursor dient als temporärer Speicher für front

    if (front == back)                                       // Liste enthält nur ein Listenelement
    {
        delete front;                                        // Listenelement löschen. Liste ist jetzt leer, weil es sowieso nur ein Element gab
        front = nullptr;
        back = nullptr;                                      // Bildlich:  nullptr <-- Element --> nullptr
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);                             // setzt den Zeiger prev auf den nullptr, da kein Element vorher existiert
        delete cursor;                                       // altes erstes bzw. vorderstes Element wird gelöscht
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back; // einfach das Gegenteil von ausgabeVorwaerts

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}
/**
 * @brief Löscht ein Studenten in der Liste
 *
 * @param int matrikelnummer
 * @return bool
 */
bool Liste::loescheStudent(int matrikelnummer)
{
	ListenElement* cursor = front;

	while (cursor != nullptr) // Die Liste wird durchgelaufen
	{
		if (cursor->getData().getMatNr() == matrikelnummer)
		{
			// Element vorne
			if (cursor == front) // falls der gesuchte Student am Anfang der Liste liegt
			{
				front = cursor->getNext();

				if (front != nullptr) // falls front nach der Inkrementation nicht auf null zeigt
				{
					front->setPrev(nullptr); // Prev Zeiger zeigt jetzt statt auf dem Element, jetzt auf nullptr, weil er jetzt front ist
				}
				else
				{
					back = nullptr; // Liste ist nur ein Element lang. Bei der Löschung muss back und front ein nullptr sein
				}
			}
			    // Element hinten
				else if (cursor == back) // falls das Element sich als letztes befindet
				{
					back = cursor->getPrev();

					if (back != nullptr) // falls back nach Dekrementation nicht auf null zeigt, dann ist es tatsächlich back
					{
						front->setNext(nullptr); // Next-Zeiger zeigt jetzt statt Element, jetzt auf nullptr, weil das nächste Element das jetzige back ist
					}
					// else wird hier nicht gebraucht, da vorher überprüft wurde ob die Liste ein Element besitzt.
				}

			    // Element Mitte
				else // sonst ist das Element irgendwo in der Liste
				{
					cursor->getPrev()->setNext(cursor->getNext()); // Next-Zeiger des vorherigen Elements zeigt jetzt auf das nächste Element des Cursors
					cursor->getNext()->setPrev(cursor->getPrev()); // Analog dazu: Prev-Zeiger des nächsten Elements zeigt jetzt auf das vorherige Element des Cursors
				}

			std::cout << "Folgender Student wird gelöscht: ";
			cursor->getData().ausgabe(); // Daten werden ausgegeben
			delete cursor; // Student wird gelöscht.
			std::cout << "\nStudent wurde erfolgreich gelöscht ";
			return true; // Programm wird da enden. Untere Argumente werden nicht mehr erreicht

		}
		cursor = cursor->getNext(); // Inkrementation
	}

	return false;
}
