#ifndef ETAT28_H
#define ETAT28_H
#include "Etat.hpp"

class Etat28 : public Etat
{
	public:
		static Etat28* getInstance();

	private:
		static Etat28 m_instance;
        Etat28();
		void transition(Automate* a, Symbole* s);
};

#endif // ETAT28_H
