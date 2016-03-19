#ifndef ETAT4_HPP
#define ETAT4_HPP

#include "Etat.hpp"


class Etat4 : public Etat
{
	public:
		static Etat4* getInstance();

	private:
		static Etat4 m_instance;
		Etat4();
		void transition(Automate* a, Symbole* s);
};

#endif

