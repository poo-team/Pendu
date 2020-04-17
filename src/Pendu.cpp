#include "Pendu.h"
#include <cstdlib>
#include <ctype.h>
#include <time.h>
#include <chrono>
#include <random>
#include <fstream>
using namespace std;
Pendu::Pendu(int &n)
{int j=0;
 char correct_letter[27];

 mot = LireFichier();
 char first=mot[0];
 char last=mot[mot.size()-1];

 /*random_device rd; // obtain a random number from hardware
 mt19937 eng(rd()); // seed the generator
 uniform_int_distribution<> x(0,3);*/
 motcache = new char *[mot.size()];

 for (int dim_allouee = 0; dim_allouee <mot.size();dim_allouee++)
 {
     motcache[dim_allouee] = new char[2];
 }
 switch(n){
    case(1):
        for (int i=0;i<mot.size();i++)
        {   correct_letter[0]=first;
            correct_letter[1]=last;
            j=2;
            motcache[i][0]=mot[i];
            if(first==motcache[i][0] || last==motcache[i][0])
            {
                motcache[i][1]='1';
            }
            else
                motcache[i][1]='0';
        }
        break;
    case(2):
        for (int i=0;i<mot.size();i++)
        {
            motcache[i][0]=mot[i];
            motcache[i][1]='0';
        }
        break;
 }
}
Pendu::Pendu(string word)
{
    int j=0;
    char correct_letter[27];
    mot = word;
    motcache = new char *[mot.size()];
    for (int dim_allouee = 0; dim_allouee <mot.size();dim_allouee++)
    {
        motcache[dim_allouee] = new char[2];
    }
    for (int i=0;i<mot.size();i++)
        {
            motcache[i][0]=toupper(mot[i]);
            motcache[i][1]='0';
        }
}
Pendu::~Pendu()
{
    delete[] motcache;
}
void Pendu::affiche()
{
    for(int i=0;i<mot.size();i++)
    {
        switch(motcache[i][1]){
            case('0'):
                cout<<"-";
                break;
            case('1'):
                cout<<motcache[i][0];
                break;
        }
     }
     cout<<endl;
}
bool Pendu::deja_saisie(char &c)
{   bool Z=false;
    for(int k=0;k<j;k++)
    {
        if (correct_letter[k]==c)
            Z=true;
    }
    return Z;
}
int Pendu::existe(char &c, int &nb_essai)
{
    int t=0;
    int win=1;
    if (deja_saisie(c))
    {
        cout<<"Vous Avez Deja Saisie Cette Letter"<<endl;
        cout<<"Il Vous Reste "<<nb_essai<<" Essais"<<endl;
    }
    else{
        for (int i=0;i<mot.size();i++)
            {
                if(c == motcache[i][0])
                {
                    motcache[i][1]='1';
                    t=1;
                    correct_letter[j]=c;
                    ++j;
                }
            }
        if(t==1)
            {
                cout<<"Tres Bien"<<endl;
                affiche();
                cout<<"Il Vous Reste "<<nb_essai<<" Essais"<<endl;
            }
        else if (t==0)
            {
                --nb_essai;
                cout<<"Echec"<<endl;
                affiche();
                cout<<"Il Vous Reste "<<nb_essai<<" Essais"<<endl;
            }
    }
    for (int i=0;i<mot.size();i++)
    {
        if (motcache[i][1]=='0')
        {
            win=0;
        }

    }
    return win ;
}
int Pendu::Score(int &nb_essai)
{
    switch (nb_essai){
        case(6):{
            return(4);
            break;
        }
        case(5):{
            return(4);
            break;
        }
        case(4):{
            return(3);
            break;
        }
        case(3):{
            return(3);
            break;
        }
        case(2):{
            return(2);
            break;
        }
        case(1):{
            return(2);
            break;
        }
        case(0):{
            return(1);
            break;
        }

    }
}
char Pendu::temps(int nb_essai)
{
    char d;
    do
    {
        cout<<"Vous Avez "<<nb_essai<<" Essais"<<endl;
        cout << "Enter the letter please before 5 seconds :"<<endl;
        auto start_s = chrono::system_clock::now();
        cin>>d;
        auto stop_s = chrono::system_clock::now();
        if(stop_s - start_s >= chrono::seconds(5))
            {
                cout << "Le Temps S'est Ecoule!"<<endl;
                d=NULL;
            }
        else if(d >= 'a'&&d <= 'z' || d>= 'A'&&d <= 'Z' ){
            //c=toupper(d);
            }
            else {
                cout << "Il Faut Saisie Un Lettre"<<endl;
                d='*';
            }
    }while(d=='*');
    return (toupper(d));
}
string Pendu::LireFichier()
{
    ifstream FichierDictionnaire;
    vector<string> Dictionnaire(0);
    int i(0);
    string MotATrouver;

    FichierDictionnaire.open("C:\\Users\\Maher.bel\\Desktop\\C++\\TD_Classes_c++\\Pendu\\Mots.txt", ios::in);
    for (i = 0; !FichierDictionnaire.eof(); i++)
        {
            Dictionnaire.push_back("");
            getline(FichierDictionnaire, Dictionnaire[i]);
        }
    MotATrouver = Dictionnaire[rand() % Dictionnaire.size()];
    return MotATrouver;
}
