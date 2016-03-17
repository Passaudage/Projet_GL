#ifndef ETAT0_HPP
#define ETAT0_HPP

#include "Etat.hpp"

/* #include "Etat1.hpp" */

class Automate;
class Symbole;

class Etat0 : public Etat
{

	public:
		Etat0();
		~Etat0();
		void transition(Automate* a, Symbole* s);

};

#endif
