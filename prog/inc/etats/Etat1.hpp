#ifndef ETAT1_HPP
#define ETAT1_HPP

#include "Etat.hpp"


class Etat1 : public Etat
{
	public:
		static Etat1* getInstance();
	
	private:
		static Etat1 m_instance;
		Etat1();
		void transition(Automate* a, Symbole* s);
};

#endif

