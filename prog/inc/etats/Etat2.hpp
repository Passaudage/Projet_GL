#ifndef ETAT2_HPP
#define ETAT2_HPP

#include "Etat.hpp"


class Etat2 : public Etat
{
	
	public:
		static Etat2* getInstance();

	private:
		static Etat2 m_instance;
		Etat2();
		void transition(Automate* a, Symbole* s);
};

#endif

