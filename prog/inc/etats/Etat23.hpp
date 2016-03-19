#ifndef ETAT23_H
#define ETAT23_H
#include "Etat.hpp"

class Etat23 : public Etat
{
	public:
		static Etat23* getInstance();

	private:
		static Etat23 m_instance;
        Etat23();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT23_H
