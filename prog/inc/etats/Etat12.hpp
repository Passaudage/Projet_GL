#ifndef ETAT12_HPP
#define ETAT12_HPP

#include "Etat.hpp"


class Etat12 : public Etat
{
	public:
		static Etat12* getInstance();

	private:
		static Etat12 m_instance;
		Etat12();
		void transition(Automate* a, Symbole* s);

};

#endif

