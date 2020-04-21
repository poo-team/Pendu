#ifndef MOTUS_H
#define MOTUS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Motus
{
    public:

        Motus(string);
        Motus(int);
        string LireFichier();
        void resultat();
        int Score(int&);
        void test (string ,int tab[]);
        virtual ~Motus();
    protected:
    private:
        string motcache ;

};

#endif // MOTUS_H
