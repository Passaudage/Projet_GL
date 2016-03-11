#ifndef ETAT_HPP
#define ETAT_HPP

class Etat 
{
	Etat();
	virtual void transition(Automate* a, Symbole* s);
};
#endif 