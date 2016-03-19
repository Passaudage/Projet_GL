#ifndef ETAT25_H
#define ETAT25_H
#include "Etat.hpp"

class Etat25 : public Etat
{
	public:
		static Etat25* getInstance();

	private:
		static Etat25 m_instance;
        Etat25();

   void transition(Automate* a, Symbole* s);
};

#endif // ETAT25_H
