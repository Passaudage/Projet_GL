#ifndef ETAT21_H
#define ETAT21_H
#include "Etat.hpp"

class Etat21: public Etat
{
	public:
		static Etat21* getInstance();

	private:
		static Etat21 m_instance;
        Etat21();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT21_H
