#ifndef PENDU_H
#define PENDU_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pendu
{
    public:
        int j=0;
        char correct_letter[27];
        string mot;
        char ** motcache;
        Pendu(int&);
        Pendu(string);
        virtual ~Pendu();
        char temps(int);
        void affiche();
        int existe(char&,int&);
        bool deja_saisie(char&);
        int Score(int&);
        string LireFichier();
    protected:
    private:
};

#endif // PENDU_H