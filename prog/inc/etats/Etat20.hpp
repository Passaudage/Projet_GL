#ifndef ETAT20_H
#define ETAT20_H
#include "Etat.hpp"

class Etat20: public Etat
{
	public:
		static Etat20* getInstance();

	private:
		static Etat20 m_instance;
        Etat20();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT20_H
