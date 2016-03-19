#ifndef ETAT16TER_H
#define ETAT16TER_H
#include "Etat.hpp"

class Etat16ter : public Etat
{
	public:
		static Etat16ter* getInstance();

	private:
		static Etat16ter m_instance;
        Etat16ter();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT16TER_H
