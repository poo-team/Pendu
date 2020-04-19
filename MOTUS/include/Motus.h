#ifndef MOTUS_H
#define MOTUS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Motus
{
    public:
        string motcache ;
        Motus(string);
        Motus(int);
        string LireFichier();
        int Score(int&);
        void test (string ,int*);
        virtual ~Motus();
    protected:
    private:

};

#endif // MOTUS_H
