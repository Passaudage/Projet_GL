#ifndef ETAT16BIS_H
#define ETAT16BIS_H
#include "Etat.hpp"

class Etat16bis : public Etat
{
	public:
		static Etat16bis* getInstance();

	private:
		static Etat16bis m_instance;
        Etat16bis();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT16BIS_H
