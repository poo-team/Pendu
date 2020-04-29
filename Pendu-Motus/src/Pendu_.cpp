#include "Pendu_.h"
#include <cstdlib>
#include <ctype.h>
#include <time.h>
#include <chrono>
#include <random>
#include <fstream>
#include <cstdio>
using namespace std;
Pendu_::Pendu_(int &n)
{int nombre_correct_letter=0;
 char correct_letter[27];
 mot = LireFichier();
 char first=mot[0];
 char last=mot[mot.size()-1];
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
            nombre_correct_letter=2;
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
Pendu_::Pendu_(string word)
{
    int nombre_correct_letter=0;
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
Pendu_::~Pendu_()
{
    delete[] motcache;
}
void Pendu_::affiche()
{    cout<<'\n'<<"          ";
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
     cout<<'\n'<<endl;
}
bool Pendu_::deja_saisie(char &c)
{   bool Z=false;
    for(int k=0;k<nombre_correct_letter;k++)
    {
        if (correct_letter[k]==c)
            Z=true;
    }
    return Z;
}
int Pendu_::existe(char &c, int &nb_essai)
{
    int t=0;
    int win=1;
    if (deja_saisie(c))
    {
        cout<<"        Vous Avez Deja Saisie Cette Letter"<<endl;
        cout<<"        Il Vous Reste "<<nb_essai<<" Essais"<<endl;
    }
    else{
        for (int i=0;i<mot.size();i++)
            {
                if(c == motcache[i][0])
                {
                    motcache[i][1]='1';
                    t=1;
                    correct_letter[nombre_correct_letter]=c;
                    ++nombre_correct_letter;
                }
            }
        if(t==1)
            {
                cout<<"  --->> Tres Bien"<<endl;
                affiche();
                affiche_bob(nb_essai);
                cout<<'\t'<<" Il Vous Reste "<<nb_essai<<" Essais"<<endl;
            }
        else if (t==0)
            {
                --nb_essai;
                cout<<"  --->> Echec"<<endl;
                affiche();
                affiche_bob(nb_essai);
                cout<<'\t'<<" Il Vous Reste "<<nb_essai<<" Essais"<<endl;
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
int Pendu_::Score(int &nb_essai)
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
char Pendu_::temps(int nb_essai)
{
    char d;
    do
    {
        cout<<"        Vous Avez "<<nb_essai<<" Essais"<<endl;
        cout << "Enter the letter please before 5 seconds :"<<'\t';
        auto start_s = chrono::system_clock::now();
        d=getch();
        auto stop_s = chrono::system_clock::now();
        if(stop_s - start_s >= chrono::seconds(5))
            {
                cout <<'\t'<< " Le Temps S'est Ecoule!!"<<endl;
                d=NULL;
            }
        else if(d >= 'a'&&d <= 'z' || d>= 'A'&&d <= 'Z' ){
            }
            else {
                cout <<'\t'<< " Il Faut Saisie Un Lettre!!"<<endl;
                d='*';
            }
    }while(d=='*');
    return (toupper(d));
}
string Pendu_::LireFichier()
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
}

void Pendu_::affiche_bob(int nb_essai)
{

    switch (nb_essai)
    {
    case 6 :
        {
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"-----------------"<<endl;
            break;
        }
    case 5 :
        {
            cout<<'\t'<<"-----------------"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"-----------------"<<endl;
            break;
        }
    case 4 :
        {
            cout<<'\t'<<"-----------------"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"-----------------"<<endl;
            break;
        }
    case 3 :
        {
            cout<<'\t'<<"-----------------"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         / \\"<<endl;
            cout<<'\t'<<"|        |* *|"<<endl;
            cout<<'\t'<<"|         \\ /"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"|"<<endl;
            cout<<'\t'<<"-----------------"<<endl;
            break;
        }
    case 2 :
        {
            cout<<'\t'<<"-----------------"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         / \\"<<endl;
            cout<<'\t'<<"|        |* *|"<<endl;
            cout<<'\t'<<"|         \\ /"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         / \\"<<endl;
            cout<<'\t'<<"|        /   \\"<<endl;
            cout<<'\t'<<"|       /     \\"<<endl;
            cout<<'\t'<<"-----------------"<<endl;
            break;
        }
    case 1 :
        {
            cout<<'\t'<<"-----------------"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         / \\"<<endl;
            cout<<'\t'<<"|        |* *|"<<endl;
            cout<<'\t'<<"|         \\ /"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         /| \\ "<<endl;
            cout<<'\t'<<"|        / |  \\"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         / \\"<<endl;
            cout<<'\t'<<"|        /   \\"<<endl;
            cout<<'\t'<<"|       /     \\"<<endl;
            cout<<'\t'<<"-----------------"<<endl;
            break;
        }
    case 0 :
        {
            cout<<'\n'<<'\t'<<"-----------------"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         / \\"<<endl;
            cout<<'\t'<<"|        |@ @|"<<endl;
            cout<<'\t'<<"|         \\ /"<<endl;
            cout<<'\t'<<"|       ~~~~~~~~ T'es mort"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         /| \\ "<<endl;
            cout<<'\t'<<"|        / |  \\"<<endl;
            cout<<'\t'<<"|          | "<<endl;
            cout<<'\t'<<"|         / \\"<<endl;
            cout<<'\t'<<"|        /   \\"<<endl;
            cout<<'\t'<<"|       /     \\"<<endl;
            cout<<'\t'<<"-----------------"<<endl;
            break;
        }
    }
}

void Pendu_::affiche_win(int score)
{
         cout<<'\n'<<"  --->> Felicitation Le Mot Est:"<<mot<<endl;
         cout<<"  --->> Score = "<<score<<endl;
         cout<<'\n'<<'\t'<<"-----------------"<<endl;
         cout<<'\t'<<"|            "<<endl;
         cout<<'\t'<<"|         / \\"<<endl;
         cout<<'\t'<<"|        |* *|"<<endl;
         cout<<'\t'<<"|         \\ /"<<endl;
         cout<<'\t'<<"|        \\ | /"<<endl;
         cout<<'\t'<<"|         \\|/ "<<endl;
         cout<<'\t'<<"|          |  "<<endl;
         cout<<'\t'<<"|          | "<<endl;
         cout<<'\t'<<"|         / \\"<<endl;
         cout<<'\t'<<"|        /   \\"<<endl;
         cout<<'\t'<<"|       /     \\"<<endl;
         cout<<'\t'<<"-----------------"<<endl;
}