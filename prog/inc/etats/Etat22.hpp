#ifndef ETAT22_H
#define ETAT22_H
#include "Etat.hpp"

class Etat22: public Etat
{
	public:
		static Etat22* getInstance();

	private:
		static Etat22 m_instance;
        Etat22();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT22_H
