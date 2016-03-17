#ifndef ETAT25_H
#define ETAT25_H


class Etat25
{
    public:
        Etat25();
        virtual ~Etat25();

   void transition(Automate* a, Symbole* s);
};

#endif // ETAT25_H
