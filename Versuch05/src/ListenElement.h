//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* prev; // prev ist ein Zeiger auf das vorherige Element welches zu next entgegengerichtet ist um eine doppelt verkettete Liste realisieren zu können

public:
    ListenElement(Student pData, ListenElement* pNext, ListenElement* prev); // Erweiterung um einen Zeiger (Konstruktor)
    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrev(ListenElement* prev); // Konstruktor um den Zeiger dem vorherigen Element zu übergeben. --> Änderung in ListenElement.cpp

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrev() const; // Konstruktor damit die Methode den Zeiger des vorherigen Elements zurückgibt, damit man in der Liste rückwärts laufen kann
};

#endif
