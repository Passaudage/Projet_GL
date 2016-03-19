#ifndef ETAT19_H
#define ETAT19_H
#include "Etat.hpp"

class Etat19: public Etat
{
	public:
		static Etat19* getInstance();

	private:
		static Etat19 m_instance;
        Etat19();
		void transition(Automate* a, Symbole* );
};

#endif // ETAT19_H
