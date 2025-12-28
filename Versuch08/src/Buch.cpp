#include "Buch.h"
#include <iostream>

/*
 *
 */
Buch::Buch(std::string initTitel, std::string initAutor)
    : Medium(initTitel), autor(initAutor)
{
	// TODO Auto-generated constructor stub
}

Buch::~Buch()
{
	// TODO Auto-generated destructor stub
}

void Buch::ausgabe(std::ostream& out) const // überladung von <<
{
	Medium::ausgabe(out);
	out << "Autor: " << autor << std::endl;
}
