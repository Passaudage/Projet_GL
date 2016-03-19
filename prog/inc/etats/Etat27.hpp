#ifndef ETAT27_H
#define ETAT27_H
#include "Etat.hpp"

class Etat27 : public Etat
{
	public:
		static Etat27* getInstance();

	private:
		static Etat27 m_instance;
        Etat27();
		void transition(Automate* a, Symbole* );
};

#endif // ETAT27_H
