#ifndef PENDU__H
#define PENDU__H
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class Pendu_
{
     public:
        Pendu_(int&);
        Pendu_(string);
        virtual ~Pendu_();
        char temps(int);
        void affiche();
        int existe(char&,int&);
        bool deja_saisie(char&);
        int Score(int&);
        string LireFichier();
        void affiche_bob(int);
        void affiche_win(int);
    protected:
    private:
        int nombre_correct_letter=0;
        char correct_letter[27];
        string mot;
        char ** motcache;
        char first;
        char last;
};

#endif // PENDU__H
