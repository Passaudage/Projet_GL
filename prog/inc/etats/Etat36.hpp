#ifndef ETAT36_HPP
#define ETAT36_HPP
#include "Etat.hpp"

class Etat36 : public Etat
{
    public:
        Etat36();
        virtual ~Etat36();
	void transition(Automate* a, Symbole* );
    protected:

    private:
};

#endif // ETAT36_HPP
