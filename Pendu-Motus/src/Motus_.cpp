#include "Motus_.h"
#include <cstdlib>
#include <ctype.h>
#include <time.h>
#include <chrono>
#include <random>
#include <fstream>
using namespace std;

Motus_::Motus_(string mot)
{
        motcache.append(1,toupper(mot[0])) ;
        cout<<'\n'<<'\t';
        cout << motcache[0] ;
        for (int i=1 ; i<mot.size()-1 ; i++)
        {
             motcache.append(1,toupper(mot[i])) ;
             cout << "*" ;
        }
         motcache.append(1,toupper(mot[mot.size()-1])) ;
         cout << motcache[motcache.size()-1]<<endl;
         cout<<'\n';
}
Motus_::Motus_(int n)
{
  motcache = LireFichier();
 switch(n){
    case(1):
        cout<<'\n'<<'\t';
        cout << motcache[0] ;

        for (int i=0 ; i<motcache.size()-2 ; i++)
        {
            cout << "*" ;
        }

        cout << motcache[(motcache.size()-1)]<<endl;
        cout<<'\n';


        break;
    case(2):
        cout<<'\n'<<'\t';
        for (int i=0;i<motcache.size();i++)
        {
            cout << "*";
        }
        cout<<'\n';
        cout<<endl;
        break;
 }
}

Motus_::~Motus_()
{

}
string Motus_::LireFichier()
{
    srand(time(0));

   ifstream fichier("Mots.txt");

   string mot, ligne, motHasard;
   int nombre(0);
   vector<string> tableau(0);

   if(fichier)
   {
       while(getline(fichier, ligne))
       {
           tableau.push_back(ligne);
       }
       nombre = rand() % tableau.size();
    mot=tableau[nombre];
	return mot ;

   }
   else
   {
       cout << "ERREUR !";
   }

   return 0;
}

int Motus_::Score(int &nb_essai)
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
void Motus_::test(string motpropose, int tab[] )
{ int k,p,n;
    n=motpropose.size();
    p=motcache.size() ;

    char copie[p] ;


    for (int i=0 ; i<p;i++)
    {
          copie[i]=motcache[i] ;
    }
    for (int i=0 ; i<n;i++)
        {
        if(toupper(motpropose[i]) ==motcache[i])
        {
            tab[i]    = 1;
            copie[i] = '*';
        }
        else
        {
            tab[i]=0;
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
		 cout<<'\t'<<"la lettre num "<<i+1<<" n'existe pas"<<endl;
	     }
	     break;

	case 1:
	     {
		 cout<<'\t'<<"la lettre num "<<i+1<<" est bien placee"<<endl;
	     }
	     break;

	case 2:
	     {
		 cout<<"la lettre num "<<i+1<<" est mal placee"<<endl;
	     }
	}
    }
    cout<<'\n';
}
void Motus_::resultat()
    {
    int nb_essai=6;
    int k,n,score;
    int *tab;
    string motproposee;

    n=0;
    int t=0;
    while ((nb_essai!=0)&&(t!=motcache.size()))
        {
            cout << "Entrer le Mot SVP vous avez "<< nb_essai<<" essai:"<<'\t';
            cin>>motproposee;
            while (motproposee.size()>motcache.size())
            {
            cout <<'\t'<< "votre essai doit etre du meme longueur que la mot!! "<<endl;
            cout << "Entrer le Mot SVP vous avez "<< nb_essai<<" essai:"<<'\t';
            cin>>motproposee;
            }
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


             {score=Score(nb_essai);
             cout<<'\t'<< " --->> Felicitation !! "<<endl ;
             cout<<'\t'<<" --->> score = "<<score<<endl;
             delete [] tab ;

    }

    else
        if (nb_essai==0)
        {
            cout<<'\t'<<" --->> vous avez perdu !!"<<endl;
            delete [] tab ;
        }

}
