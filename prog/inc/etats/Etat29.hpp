#ifndef ETAT29_H
#define ETAT29_H
#include "Etat.hpp"

class Etat29 : public Etat
{
	public:
		static Etat29* getInstance();

	private:
		static Etat29 m_instance;
        Etat29();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT29_H
