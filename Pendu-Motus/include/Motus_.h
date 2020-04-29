#ifndef MOTUS__H
#define MOTUS__H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Motus_
{
    public:
        Motus_(string);
        Motus_(int);
        string LireFichier();
        void resultat();
        int Score(int&);
        void test (string ,int tab[]);
        virtual ~Motus_();
    protected:
    private:
        string motcache ;
};

#endif // MOTUS__H
