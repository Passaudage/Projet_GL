#ifndef ETAT6_HPP
#define ETAT6_HPP

#include "Etat.hpp"


class Etat6 : public Etat
{
	public:
		static Etat6* getInstance();

	private:
		static Etat6 m_instance;
		Etat6();
		void transition(Automate* a, Symbole* );
};

#endif
