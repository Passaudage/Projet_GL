#ifndef ETAT5_HPP
#define ETAT5_HPP

#include "Etat.hpp"

class Etat5 : public Etat
{
	public:
		static Etat5* getInstance();

	private:
		static Etat5 m_instance;
		Etat5();
		void transition(Automate* a, Symbole* s);
};

#endif

