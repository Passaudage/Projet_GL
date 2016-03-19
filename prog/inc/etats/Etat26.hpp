#ifndef ETAT26_H
#define ETAT26_H
#include "Etat.hpp"

class Etat26 : public Etat
{
	public:
		static Etat26* getInstance();

	private:
		static Etat26 m_instance;
        Etat26();

    void transition(Automate* a, Symbole* s);
};

#endif // ETAT26_H
