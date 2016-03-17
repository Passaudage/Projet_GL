#ifndef ETAT1_HPP
#define ETAT1_HPP

#include <iostream>
#include "Etat.hpp"
#include "Automate.hpp"
#include "Symbole.hpp"
#include "Etat2.hpp"
#include "Etat10.hpp"
#include "Etat3.hpp"
#include "Etat4.hpp"
#include "Etat8.hpp"
#include "Etat5.hpp"
#include "Etat7.hpp"

class Etat1 : public Etat
{
	public:
		Etat1();
		~Etat1();
		void transition(Automate* a, Symbole* s);

};

#endif

