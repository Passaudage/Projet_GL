#ifndef ETAT8_HPP
#define ETAT8_HPP

#include "Etat.hpp"

class Etat8 : public Etat
{
	public:
		static Etat8* getInstance();

	private:
		static Etat8 m_instance;
		Etat8();
		void transition(Automate* a, Symbole* s);
};

#endif

