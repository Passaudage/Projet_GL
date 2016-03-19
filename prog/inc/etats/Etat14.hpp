#ifndef ETAT14_HPP
#define ETAT14_HPP

#include "Etat.hpp"

class Etat14 : public Etat
{
	public:
		static Etat14* getInstance();

	private:
		static Etat14 m_instance;
		Etat14();
		void transition(Automate* a, Symbole* );

};

#endif

