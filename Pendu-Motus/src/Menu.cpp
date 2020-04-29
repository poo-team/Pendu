#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
int Menu::Menu_Principal()
{
    int jeu;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------Pendu+Motus -------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<'\t'<<"*****************<MENU>*************************"<<endl;
    cout<<'\t'<<"*  1--> Jouer Le Pendu                         *"<<endl;
    cout<<'\t'<<"*  2--> Jouer Motus                            *"<<endl;
    cout<<'\t'<<"*  3--> Credits                                *"<<endl;
    cout<<'\t'<<"*  0--> Exit                                   *"<<endl;
    cout<<'\t'<<"************************************************"<<endl;
    cout<<'\n'<<"        Entrez Votre Choix ?? "<<'\t';
    cin>>jeu;
    return jeu;

}
int Menu::Menu_pendu()
{
    int mode;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------Pendu--------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<'\t'<<"*****************<MENU>*********************************"<<endl;
    cout<<'\t'<<"*  1--> Jouer Le Pendu Contre l'Ordinateur (montre)    *"<<endl;
    cout<<'\t'<<"*  2--> Jouer Le Pendu Contre Un jouer                 *"<<endl;
    cout<<'\t'<<"********************************************************"<<endl;
    cout<<'\n'<<"        Entrez Votre Choix ?? "<<'\t';
    cin>>mode;
    return mode;

}
int Menu::Menu_pendu_solo()
{
    int niveau;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------Choisir le Niveau---------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<'\t'<<"*****************<MENU>*********************************"<<endl;
    cout<<'\t'<<"*  1--> Normal                                         *"<<endl;
    cout<<'\t'<<"*  2--> Difficile                                      *"<<endl;
    cout<<'\t'<<"********************************************************"<<endl;
    cout<<'\n'<<"        Entrez Votre Choix ?? "<<'\t';
    cin>>niveau;
    return niveau;
    system("cls");
}
string Menu::Menu_pendu_multijoueur()
{
    string word;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------Pendu Multijoueur---------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<'\n'<<"      Entrez Votre Votre Mot Joueur 1:"<<'\t';
    cin>>word;
    return word;

}
int Menu::Menu_motus()
{
    int mode;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------Motus -------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<'\t'<<"*****************<MENU>*************************"<<endl;
    cout<<'\t'<<"*  1--> Jouer Motus Contre l'Ordinateur        *"<<endl;
    cout<<'\t'<<"*  2--> Jouer Motus Contre Un jouer            *"<<endl;
    cout<<'\t'<<"************************************************"<<endl;
    cout<<'\n'<<"        Entrez Votre Choix ?? "<<'\t';
    cin>>mode;
    return mode;

}
 int Menu::Menu_motus_solo()
 {
    int niveau ;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------Choisir le Niveau---------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<'\t'<<"*****************<MENU>*********************************"<<endl;
    cout<<'\t'<<"*  1--> Normal                                         *"<<endl;
    cout<<'\t'<<"*  2--> Difficile                                      *"<<endl;
    cout<<'\t'<<"********************************************************"<<endl;
    cout<<'\n'<<"        Entrez Votre Choix ?? "<<'\t';
    cin>>niveau;
    return niveau;
 }
 string Menu::Menu_motus_multijoueur()
 {
     string motpropose;
     cout<<"----------------------------------------------------------------------------"<<endl;
     cout<<"--------------------------Motus Multijoueur---------------------------------"<<endl;
     cout<<"----------------------------------------------------------------------------"<<endl;
     cout<<endl;
     cout<<'\n'<<"      Entrez Votre Votre Mot Joueur 1:"<<'\t';
     cin>>motpropose;
     return motpropose;

 }
 int Menu::Menu_Rejouer()
 {
     int choix;
     cout<<"----------------------------------------------------------------------------"<<endl;
     cout<<"------------------------------Game Over-------------------------------------"<<endl;
     cout<<"----------------------------------------------------------------------------"<<endl;
     cout<<endl;
     cout<<'\t'<<"************************************************"<<endl;
     cout<<'\t'<<"*  1--> Rejouer                                *"<<endl;
     cout<<'\t'<<"*  2--> Exit to Menu                           *"<<endl;
     cout<<'\t'<<"************************************************"<<endl;
     cout<<'\n'<<"        Entrez Votre Choix ?? "<<'\t';
     cin >> choix;
     return choix;
 }

void Menu::Menu_credit()
{   cout<<'\n';
    cout<<'\t'<<"*****************<Credit by Poo-Team >*******************"<<endl;
    cout<<'\t'<<"*   --> Maher Benltaif                                  *"<<endl;
    cout<<'\t'<<"*   --> Wiem Babou                                      *"<<endl;
    cout<<'\t'<<"*   --> Eya Aribi                                       *"<<endl;
    cout<<'\t'<<"*********************************************************"<<endl;
}
