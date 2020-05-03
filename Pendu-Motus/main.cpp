#include <iostream>
#include <Pendu_.h>
#include <Motus_.h>
#include <Menu.h>
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
using namespace std;
int niveau;
string word;
int score=0;
int fin=0;
char Lettre;
int jeu;
int mode;
int choix;
int gagne;
bool Rejouer = false ;
bool to_menu = false ;
int nb_essai=6;
string motpropose;
int main()
{do{ // boucle pour l'options rejouer et retour au menu
    Menu menu;
    jeu = menu.Menu::Menu_Principal();
    system("cls");
    while(jeu != 1 && jeu != 2 && jeu != 3 && jeu !=0) // Exception des erreurs de saisie par le joueur
    {
        cout<<'\t'<<"taper 1 ou 2 pour votre choix! "<<endl;
        jeu = menu.Menu::Menu_Principal();
        system("cls");
    }
    if(jeu==1){
            do
            {
            mode=menu.Menu::Menu_pendu();
            system("cls");
            while(mode != 1 && mode != 2)// Exception des erreurs de saisie par le joueur
            {
                cout<<'\t'<<"taper 1 ou 2 pour votre choix! "<<endl;
                mode=menu.Menu::Menu_pendu();
                system("cls");
            }
            if(mode==1){
                int nb_essai=6;
                niveau=menu.Menu::Menu_pendu_solo();
                system("cls");
                while(niveau != 1 && niveau != 2)// Exception des erreurs de saisie par le joueur
                {
                     cout<<'\t'<<"taper 1 ou 2 pour votre choix! "<<endl;
                     niveau=menu.Menu::Menu_pendu_solo();
                     system("cls");
                }
                Pendu_ p1(niveau);
                p1.affiche();
                p1.affiche_bob(nb_essai);
                while (nb_essai!=0)
                {
                        Lettre=p1.temps(nb_essai);
                        gagne = p1.Pendu_::existe(Lettre,nb_essai);
                        if(gagne==1)
                        {
                            score=p1.Pendu_::Score(nb_essai);
                            p1.affiche_win(score);
                            p1.~Pendu_();
                            break;
                        }
                  }

                if (nb_essai==0 && gagne==0)
                {
                    cout<<'\n'<<'\t'<<" --->> Vous Avez Perdu"<<endl;
                    p1.~Pendu_();
                    p1.affiche_bob(nb_essai);
                }
            }
            else if(mode==2){
                int nb_essai=6;
                word=menu.Menu::Menu_pendu_multijoueur();
                system("cls");
                Pendu_ p1(word);
                p1.affiche();
                p1.affiche_bob(nb_essai);
                cout<<'\t'<<"Vous Avez 6 Essais"<<endl;
                while (nb_essai!=0)
                {
                    cout <<'\t'<< "Entrer La Lettre SVP:";
                    Lettre=getch();
                    Lettre=toupper(Lettre);
                    gagne = p1.Pendu_::existe(Lettre,nb_essai);
                    if(gagne==1)
                    {
                        score=p1.Pendu_::Score(nb_essai);
                        p1.affiche_win(score);
                        p1.~Pendu_();
                        break;
                    }

                }
                if (nb_essai==0 && gagne==0)
                {
                    cout<<'\n'<<'\t'<<" --->> Vous Avez Perdu"<<endl;
                    p1.~Pendu_();
                    p1.affiche_bob(nb_essai);
                }
            }
            choix = menu.Menu::Menu_Rejouer();
            system("cls");
            while(choix != 1 && choix != 2)// Exception des erreurs de saisie par le joueur
            {
                cout<<'\t'<<"taper 1 ou 2 pour votre choix! "<<endl;
                choix = menu.Menu::Menu_Rejouer();
                system("cls");
            }
            switch (choix)
            {
                case 1 :
                    Rejouer = true;
                    break;
                case 2 :
                    to_menu = true;
                    break;
            }

           }while (	Rejouer);
    }
    else if (jeu==2){
        do
        {
        mode=menu.Menu::Menu_motus();
        system("cls");
        while(mode != 1 && mode != 2)// Exception des erreurs de saisie par le joueur
            {
                cout<<'\t'<<"taper 1 ou 2 pour votre choix! "<<endl;
                mode=menu.Menu::Menu_motus();
                system("cls");
            }
        if(mode==1){
            niveau=menu.Menu::Menu_motus_solo();
            system("cls");
            while(niveau != 1 && niveau != 2)// Exception des erreurs de saisie par le joueur
                {
                    cout<<'\t'<<"taper 1 ou 2 pour votre choix! "<<endl;
                      niveau=menu.Menu::Menu_motus_solo();
                      system("cls");
                }
            Motus_ m1(niveau);
            cout<<'\t'<<"vous avez 6 essais"<<endl;
            m1.resultat();

            }
        else if(mode==2){
            motpropose=menu.Menu::Menu_motus_multijoueur();
            system("cls");
            Motus_ m2(motpropose);
            cout<<'\t'<<"vous avez 6 essais"<<endl;
            m2.resultat();
            }
        choix = menu.Menu::Menu_Rejouer();
        system("cls");
        while(choix != 1 && choix != 2)// Exception des erreurs de saisie par le joueur
            {
                cout<<'\t'<<"taper 1 ou 2 pour votre choix! "<<endl;
                choix = menu.Menu::Menu_Rejouer();
                system("cls");
            }
        switch (choix)
        {
            case 1 :
                Rejouer = true;
                break;
            case 2 :
                to_menu = true;
                break;
        }

        }while (Rejouer);
    }
    else if (jeu==3)
    {
        menu.Menu::Menu_cree();
    }
    else if (jeu ==0)
    {
        exit(0);
    }
  }while (to_menu);
}
