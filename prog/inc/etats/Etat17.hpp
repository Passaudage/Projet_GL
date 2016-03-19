#ifndef ETAT17_HPP
#define ETAT17_HPP

#include "Etat.hpp"

class Etat17 : public Etat
{
	public:
		static Etat17* getInstance();

	private:
		static Etat17 m_instance;
		Etat17();
		void transition(Automate* a, Symbole* s);
};

#endif

