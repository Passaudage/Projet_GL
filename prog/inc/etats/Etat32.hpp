#ifndef ETAT32_H
#define ETAT32_H
#include "Etat.hpp"

class Etat32 : public Etat
{
	public:
		static Etat32* getInstance();

	private:
		static Etat32 m_instance;
        Etat32();
		void transition(Automate* a, Symbole* );
};

#endif // ETAT32_H
