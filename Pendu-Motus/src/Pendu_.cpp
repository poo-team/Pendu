#include "Pendu_.h"
#include <cstdlib>
#include <ctype.h>
#include <time.h>
#include <chrono>
#include <random>
#include <fstream>
#include <cstdio>
using namespace std;
Pendu_::Pendu_(int &n)//constructeur (jouer contre montre)
{int nombre_correct_letter=0;
 char correct_letter[27];// les lettres saisies par le joueur et qui sont correct
 mot = LireFichier();// choisir aleatoire du mot a partir du fichier
 char first=mot[0];// premier lettre du mot
 char last=mot[mot.size()-1];// dernier lettre du mot
 motcache = new char *[mot.size()];

 for (int dim_allouee = 0; dim_allouee <mot.size();dim_allouee++) //allocation dynamique du tableau
 {
     motcache[dim_allouee] = new char[2];
 }
 switch(n){
    case(1): // niveau normal
        for (int i=0;i<mot.size();i++)// remplissage du tableau
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
    case(2): // niveau difficile
        for (int i=0;i<mot.size();i++)// remplissage du tableau
        {
            motcache[i][0]=mot[i];
            motcache[i][1]='0';
        }
        break;
 }
}
Pendu_::Pendu_(string word)// constructeur (Multijoueur)
{
    int nombre_correct_letter=0;
    char correct_letter[27];
    mot = word;
    motcache = new char *[mot.size()];
    for (int dim_allouee = 0; dim_allouee <mot.size();dim_allouee++)//allocation dynamique du tableau
    {
        motcache[dim_allouee] = new char[2];
    }
    for (int i=0;i<mot.size();i++)// remplissage du tableau
        {
            motcache[i][0]=toupper(mot[i]);
            motcache[i][1]='0';
        }
}
Pendu_::~Pendu_()// destructeur
{
    delete[] motcache;
}
void Pendu_::affiche()// afficher le mot cach�
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
        if (correct_letter[k]==c)// si la lettre saisie dans cette essai �t� saisie par le joueur ou pas et existant dans le mot
            Z=true;
    }
    return Z;
}
int Pendu_::existe(char &c, int &nb_essai)
{
    int lettre_existe=0;
    int win=1;
    if (deja_saisie(c))
    {
        cout<<"        Vous Avez Deja Saisie Cette Letter"<<endl;
        cout<<"        Il Vous Reste "<<nb_essai<<" Essais"<<endl;
    }
    else{
        for (int i=0;i<mot.size();i++)// parcours du mot lettre par lettre
            {
                if(c == motcache[i][0])// si la lettre exite dans le mot
                {
                    motcache[i][1]='1';
                    lettre_existe=1;
                    correct_letter[nombre_correct_letter]=c;//ajouter la lettre au tableau du correct_lettre
                    ++nombre_correct_letter;
                }
            }
        if(lettre_existe==1)
            {
                cout<<c<<"  --->> Tres Bien"<<endl;
                affiche();//afficher le mot cach� apres cette essai
                affiche_bob(nb_essai); // afficher le gar�on (bob)
                cout<<'\t'<<" Il Vous Reste "<<nb_essai<<" Essais"<<endl;
            }
        else if (lettre_existe==0)
            {
                --nb_essai;//decrementer le nommbre d essai
                cout<<c<<"  --->> Echec"<<endl;
                affiche();//afficher le mot cach� apres cette essai
                affiche_bob(nb_essai);// afficher le gar�on (bob)
                cout<<'\t'<<" Il Vous Reste "<<nb_essai<<" Essais"<<endl;
            }
    }
    for (int i=0;i<mot.size();i++)
    {
        if (motcache[i][1]=='0')// le mot n'est pas totalement d�couverte
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
        cout << "Entrer La Lettre SVP avant 5 secondes :";
        auto start_s = chrono::system_clock::now();// enregistrer l'heure de d�but
        d=getch();// lire la lettre
        auto stop_s = chrono::system_clock::now();// enregistrer l'heure de fin
        if(stop_s - start_s >= chrono::seconds(5))// si la difference du temps superieur a 5s
            {
                cout <<'\t'<< " Le Temps S'est Ecoule!!"<<endl;
                d=NULL;
            }
        else if(d >= 'a'&&d <= 'z' || d>= 'A'&&d <= 'Z' ) // si la character saisie est une lettre
            {}
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
