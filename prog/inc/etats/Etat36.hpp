#ifndef ETAT36_HPP
#define ETAT36_HPP
#include "Etat.hpp"

class Etat36 : public Etat
{
	public:
		static Etat36* getInstance();

	private:
		static Etat36 m_instance;
        Etat36();
		void transition(Automate* a, Symbole* );
};

#endif // ETAT36_HPP
