#ifndef ETAT9_HPP
#define ETAT9_HPP

#include "Etat.hpp"

class Etat9 : public Etat
{
	public:
		static Etat9* getInstance();

	private:
		static Etat9 m_instance;
		Etat9();
		void transition(Automate* a, Symbole* s);
};

#endif

