#ifndef ETAT3_HPP
#define ETAT3_HPP

#include "Etat.hpp"


class Etat3 : public Etat
{

	public:
		static Etat3* getInstance();

	private:
		static Etat3 m_instance;
		Etat3();
		void transition(Automate* a, Symbole* s);
};

#endif

