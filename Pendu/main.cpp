#include <iostream>
#include <Pendu.h>
#include <ctype.h>
#include <cstdlib>
using namespace std;
int niveau;
string word;
int score=0;
char c;
int mode;
int choix;
int gagne;
bool Rejouer = false ;
int nb_essai=6;
int main()
{   cout<<"Pendu:"<<endl;
    cout<<"1-Jouer Solo Contre Montre"<<endl;
    cout<<"2-Jouer Avec Ami(e)"<<endl;
    cin>>mode;
    if(mode==1){
        cout<<"Choisir Le Niveau:"<<endl;
        cout<<"1-Normal"<<endl;
        cout<<"2-Difficile"<<endl;
        cin>>niveau;
        Pendu p1(niveau);
        p1.affiche();

        while (nb_essai!=0)
        {
                c=p1.temps(nb_essai);
                gagne = p1.Pendu::existe(c,nb_essai);
                if(gagne==1)
                {
                    cout<<"Felicitation Le Mot Est:"<<p1.mot<<endl;
                    score=p1.Pendu::Score(nb_essai);
                    cout<<"Score = "<<score<<endl;
                    break;
                }
          }

        if (nb_essai==0 && gagne==0)
        {
            cout<<"Vous Etes Perdu"<<endl;
        }
        return 0;
    }
    else if(mode==2){
        cout<<"Saisie Votre Mot Joueur 1:"<<endl;
        cin>>word;
        Pendu p1(word);
        p1.affiche();
        cout<<"Vous Avez 6 Essais"<<endl;
        while (nb_essai!=0)
        {
            cout << "Entrer La Lettre SVP:"<<endl;
            cin>>c;
            c=toupper(c);
            gagne = p1.Pendu::existe(c,nb_essai);
            if(gagne==1)
            {
                cout<<"Felicitation Le Mot Est:"<<p1.mot<<endl;
                score=p1.Pendu::Score(nb_essai);
                cout<<"Score = "<<score<<endl;
                break;
            }

        }
        if (nb_essai==0 && gagne==0)
        {
            cout<<"Vous Avez Perdu"<<endl;
        }
        return 0;
    }
}
