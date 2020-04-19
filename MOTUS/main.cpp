#include <iostream>
#include <Motus.h>
#include <ctype.h>
using namespace std;
int niveau;
string word;
int score=0 , fin=0;
string motproposee;
int mode,k,n;
int nb_essai=6;


int main()
{
    cout<<"Motus:"<<endl;
    cout<<"1-jouer solo"<<endl;
    cout<<"2-jouer avec ami(e)"<<endl;
    cin>>mode;
    if(mode==1){
        cout<<"choisir le niveau:"<<endl;
        cout<<"1-normal"<<endl;
        cout<<"2-difficile"<<endl;
        cin>>niveau;
        Motus m(niveau);
        cout<<"vous avez 6 essais"<<endl;

        while ((nb_essai!=0)&&(k!=m.motcache.size()))
        {
            cout << "Entrer le Mot SVP:"<<endl;
            cin>>motproposee;
            n=motproposee.size();
            int tab  [n];
            m.Motus::test(motproposee,tab);
            int k=0 ;
            while ((tab[k]== 1)&&(m.motcache.size()==n)&& (k<n))
            {
                k++;
                }
                nb_essai--;
                 }
    if (k ==m.motcache.size())
    {
        cout<< "1"<<endl ;
    }


        if ((k==m.motcache.size())||(nb_essai==6))
        {
             score=m.Motus::Score(nb_essai);
             cout<<"score = "<<score<<endl;
        }
        else
        {
            cout<<"vous avez perdu"<<endl;
        }
    }

     else if(mode==2){
        cout<<"saisie votre mot joueur1:"<<endl;
        cin>>word;
        Motus m1(word);
        cout<<"vous avez 6 essais"<<endl;
         while ((nb_essai!=0)&&(k!=m1.motcache.size()))
        {
            cout << "Entrer le Mot SVP:"<<endl;
            cin>>motproposee;
            n=motproposee.size();
            int tab  [n];
            m1.Motus::test(motproposee,tab);
            int k=0 ;
            while ((tab[k]== 1)&&(m1.motcache.size()==n)&& (k<n))
            {
                k++;
                }
                nb_essai--;
                 }
    if (k ==m1.motcache.size())
    {
        cout<< "1"<<endl ;
    }


        if ((k==m1.motcache.size())||(nb_essai==6))
        {
             score=m1.Motus::Score(nb_essai);
             cout<<"score = "<<score<<endl;
        }
        else
        {
            cout<<"vous avez perdu"<<endl;
        }
    }
        return 0;

}


