#include "Motus.h"
#include <cstdlib>
#include <ctype.h>
#include <time.h>
#include <chrono>
#include <random>
#include <fstream>
using namespace std;

Motus::Motus(string mot)
{
        motcache = mot ;
        cout << mot[0] ;
        for (int i=0 ; i<mot.size()-2 ; i++)
        {
            cout << "*" ;
        }
        cout << mot[mot.size()-1]<<endl;

}
Motus::Motus(int n)
{
 motcache = LireFichier();
 switch(n){
    case(1):
        cout << motcache[0] ;
        for (int i=0 ; i<motcache.size()-2 ; i++)
        {
            cout << "*" ;
        }
        cout << motcache[(motcache.size()-1)]<<endl;

        break;
    case(2):
        for (int i=0;i<motcache.size();i++)
        {
            cout << "*";
        }
        cout<<endl;
        break;
 }
}

Motus::~Motus()
{

}
string Motus::LireFichier()
{
    ifstream FichierDictionnaire;
    vector<string> Dictionnaire(0);
    int i(0);
    string MotATrouver;

    FichierDictionnaire.open("C:\\Users\\samsung\\Desktop\\c++\\Mots.txt", ios::in);
    for (i = 0; !FichierDictionnaire.eof(); i++)
        {
            Dictionnaire.push_back("");
            getline(FichierDictionnaire, Dictionnaire[i]);
        }
    MotATrouver = Dictionnaire[rand() % Dictionnaire.size()];
    return MotATrouver;
}
int Motus::Score(int &nb_essai)
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
void Motus::test(string motpropose, int tab[] )
{
    int k,p,n;
    n=motpropose.size();
    p=motcache.size() ;
    char copie[p] ;


    for (int i=0 ; i<p;i++)
    {
          copie[i]=(motcache[i]) ;
    }
    for (int i=0 ; i<n;i++)
        {
        if(toupper(motpropose[i]) ==motcache[i])
        {
            tab[i]    = 1;
            copie[i] = '*';
        }
        }

     for(int i=0;i<n;i++)
    {
	 for(int j=0;j<p;j++)
	 {
	     if((toupper(motpropose[i]) == copie[j])&&(tab[i] != 1))
	     {
		 tab[i]    = 2;
		 copie[j] = '#';
		 break;
	     }
	 }
    }
     for(int i=0;i<n;i++)
    {
	switch(tab[i])
	{
	case 0:
	     {
		 cout<<"la lettre num "<<i+1<<" n'existe pas"<<endl;
	     }
	     break;

	case 1:
	     {
		 cout<<"la lettre num "<<i+1<<" est bien placee"<<endl;
	     }
	     break;

	case 2:
	     {
		 cout<<"la lettre num "<<i+1<<" est mal placee"<<endl;
	     }
	}
    }
}
void Motus::resultat()
    {
    int nb_essai=6;
    int k,n,score;
    int *tab;
    string motproposee;
    n=0;
    int t=0;
    while ((nb_essai!=0)&&(t!=motcache.size()))
        {
            cout << "Entrer le Mot SVP vous avez "<< nb_essai<<" essai:"<<endl;
            cin>>motproposee;
            n=motproposee.size();
            tab =new int [n];
            test(motproposee,tab);
            int k=0 ;
            while ((tab[k]== 1)&&(motcache.size()==n)&& (k<n))
            {
                k++;

                }
                t=k;
            nb_essai--;
        }
    if (t==motcache.size())
        {
             score=Score(nb_essai);
             cout<<"score = "<<score<<endl;
             delete [] tab ;
        }
    else
        if (nb_essai==0)
        {
            cout<<"vous avez perdu"<<endl;
        }

}
