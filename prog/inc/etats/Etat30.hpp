#ifndef ETAT30_H
#define ETAT30_H
#include "Etat.hpp"

class Etat30: public Etat
{
    public:
        Etat30();
        virtual ~Etat30();
		void transition(Automate* a, Symbole* );
    protected:

    private:
};

#endif // ETAT30_H
