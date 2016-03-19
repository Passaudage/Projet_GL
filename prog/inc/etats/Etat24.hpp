#ifndef ETAT24_H
#define ETAT24_H
#include "Etat.hpp"

class Etat24 : public Etat
{
	public:
		static Etat24* getInstance();

	private:
		static Etat24 m_instance;
        Etat24();
		void transition(Automate* a, Symbole*);
};

#endif // ETAT24_H
