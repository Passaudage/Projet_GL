#ifndef ETAT0_HPP
#define ETAT0_HPP

#include "Etat.hpp"

/* #include "Etat1.hpp" */

class Automate;
class Symbole;

class Etat0 : public Etat
{

	public:
		static Etat0* getInstance();
	
	private:
		static Etat0 m_instance;
		
		Etat0();

		void transition(Automate* a, Symbole* s);

};

#endif
