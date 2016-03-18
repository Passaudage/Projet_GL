#ifndef ETAT31_HPP
#define ETAT31_HPP
#include "Etat.hpp"

class Etat31 : public Etat
{
    public:
        Etat31();
        virtual ~Etat31();
	void transition(Automate* a, Symbole* s);
    protected:

    private:
};

#endif // ETAT31_HPP
